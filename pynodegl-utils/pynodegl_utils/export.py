import os
import platform
import subprocess

import pynodegl as ngl
from PyQt5 import QtGui, QtCore


class _PipeThread(QtCore.QThread):

    def __init__(self, fd, unused_fd, w, h, fps):
        super(_PipeThread, self).__init__()
        self.fd = fd
        self.unused_fd = unused_fd
        self.w, self.h, self.fps = w, h, fps

    def run(self):
        try:
            ret = self.run_with_except()
        except:
            raise
        finally:
            # very important in order to prevent deadlock if one thread fails
            # one way or another
            os.close(self.fd)


class _ReaderThread(_PipeThread):

    def __init__(self, fd, unused_fd, w, h, fps, filename):
        super(_ReaderThread, self).__init__(fd, unused_fd, w, h, fps)
        self._filename = filename

    def run_with_except(self):
        cmd = ['ffmpeg', '-r', str(self.fps),
               '-nostats', '-nostdin',
               '-f', 'rawvideo',
               '-video_size', '%dx%d' % (self.w, self.h),
               '-pixel_format', 'rgba',
               '-i', 'pipe:%d' % self.fd,
               '-vf', 'vflip',
               '-y', self._filename]

        #print 'Executing: ' + ' '.join(cmd)

        # Closing the unused file descriptor of the pipe is mandatory between
        # the fork() and the exec() of ffmpeg in order to prevent deadlocks
        return subprocess.call(cmd, preexec_fn=lambda: os.close(self.unused_fd))


class Exporter(QtCore.QObject):

    progressed = QtCore.pyqtSignal(int)

    def export(self, scene, filename, w, h, duration, fps):

        fd_r, fd_w = os.pipe()

        from pynodegl import Pipe, Scale
        scene = Pipe(scene, fd_w, w, h)

        reader = _ReaderThread(fd_r, fd_w, w, h, fps, filename)
        reader.start()

        # Surface Format
        gl_format = QtGui.QSurfaceFormat()
        gl_format.setVersion(3, 3)
        gl_format.setProfile(QtGui.QSurfaceFormat.CoreProfile)
        gl_format.setDepthBufferSize(24);
        gl_format.setStencilBufferSize(8);
        gl_format.setAlphaBufferSize(8);

        # GL context
        glctx = QtGui.QOpenGLContext()
        glctx.setFormat(gl_format)
        assert glctx.create() == True
        assert glctx.isValid() == True

        # Offscreen Surface
        surface = QtGui.QOffscreenSurface()
        surface.setFormat(gl_format)
        surface.create()
        assert surface.isValid() == True

        glctx.makeCurrent(surface)

        # Framebuffer
        fbo = QtGui.QOpenGLFramebufferObject(w, h)
        fbo.setAttachment(QtGui.QOpenGLFramebufferObject.CombinedDepthStencil)
        assert fbo.isValid() == True
        fbo.bind()

        # node.gl context
        ngl_viewer = ngl.Viewer()
        ngl_viewer.set_scene(scene)
        if platform.system() == 'Linux':
            ngl_viewer.configure(ngl.GLPLATFORM_GLX, ngl.GLAPI_OPENGL3)
        elif platform.system() == 'Darwin':
            ngl_viewer.configure(ngl.GLPLATFORM_CGL, ngl.GLAPI_OPENGL3)
        ngl_viewer.set_viewport(0, 0, w, h)

        # Draw every frame
        nb_frame = int(fps * duration)
        for i in range(nb_frame):
            time = i / float(fps)
            ngl_viewer.draw(time)
            self.progressed.emit(i*100 / nb_frame)
            glctx.swapBuffers(surface)
        self.progressed.emit(100)

        os.close(fd_w)
        fbo.release()
        glctx.doneCurrent()

        reader.wait()


def test_export():
    import sys

    def _get_scene(duration):
        from examples import misc
        class DummyCfg: pass
        cfg = DummyCfg()
        cfg.duration = duration
        return misc.triangle(cfg)

    def print_progress(progress):
        sys.stdout.write('\r%d%%' % progress)
        if progress == 100:
            sys.stdout.write('\n')

    if len(sys.argv) != 2:
        print 'Usage: %s <outfile>' % sys.argv[0]
        sys.exit(0)

    filename = sys.argv[1]
    duration = 5
    scene = _get_scene(duration)
    app = QtGui.QGuiApplication(sys.argv)

    exporter = Exporter()
    exporter.progressed.connect(print_progress)
    exporter.export(scene, filename, 320, 240, duration, 60)

if __name__ == '__main__':
    test_export()
