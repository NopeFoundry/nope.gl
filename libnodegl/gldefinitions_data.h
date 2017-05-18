/* DO NOT EDIT - This file is autogenerated */

#include <stddef.h>

#include "glfunctions.h"

#define M (1 << 0)

static const struct gldefinition {
    const char *name;
    size_t offset;
    int flags;
} gldefinitions[] = {
    {"glActiveTexture", offsetof(struct glfunctions, ActiveTexture), M},
    {"glAttachShader", offsetof(struct glfunctions, AttachShader), M},
    {"glBindAttribLocation", offsetof(struct glfunctions, BindAttribLocation), M},
    {"glBindBuffer", offsetof(struct glfunctions, BindBuffer), M},
    {"glBindFramebuffer", offsetof(struct glfunctions, BindFramebuffer), M},
    {"glBindRenderbuffer", offsetof(struct glfunctions, BindRenderbuffer), M},
    {"glBindTexture", offsetof(struct glfunctions, BindTexture), M},
    {"glBindVertexArray", offsetof(struct glfunctions, BindVertexArray), 0},
    {"glBlendColor", offsetof(struct glfunctions, BlendColor), M},
    {"glBlendEquation", offsetof(struct glfunctions, BlendEquation), M},
    {"glBlendEquationSeparate", offsetof(struct glfunctions, BlendEquationSeparate), M},
    {"glBlendFunc", offsetof(struct glfunctions, BlendFunc), M},
    {"glBlendFuncSeparate", offsetof(struct glfunctions, BlendFuncSeparate), M},
    {"glBlitFramebuffer", offsetof(struct glfunctions, BlitFramebuffer), 0},
    {"glBufferData", offsetof(struct glfunctions, BufferData), M},
    {"glCheckFramebufferStatus", offsetof(struct glfunctions, CheckFramebufferStatus), M},
    {"glClear", offsetof(struct glfunctions, Clear), M},
    {"glClearColor", offsetof(struct glfunctions, ClearColor), M},
    {"glColorMask", offsetof(struct glfunctions, ColorMask), M},
    {"glCompileShader", offsetof(struct glfunctions, CompileShader), M},
    {"glCreateProgram", offsetof(struct glfunctions, CreateProgram), M},
    {"glCreateShader", offsetof(struct glfunctions, CreateShader), M},
    {"glDeleteBuffers", offsetof(struct glfunctions, DeleteBuffers), M},
    {"glDeleteFramebuffers", offsetof(struct glfunctions, DeleteFramebuffers), M},
    {"glDeleteProgram", offsetof(struct glfunctions, DeleteProgram), M},
    {"glDeleteRenderbuffers", offsetof(struct glfunctions, DeleteRenderbuffers), M},
    {"glDeleteShader", offsetof(struct glfunctions, DeleteShader), M},
    {"glDeleteTextures", offsetof(struct glfunctions, DeleteTextures), M},
    {"glDeleteVertexArrays", offsetof(struct glfunctions, DeleteVertexArrays), 0},
    {"glDetachShader", offsetof(struct glfunctions, DetachShader), M},
    {"glDisable", offsetof(struct glfunctions, Disable), M},
    {"glDrawElements", offsetof(struct glfunctions, DrawElements), M},
    {"glEnable", offsetof(struct glfunctions, Enable), M},
    {"glEnableVertexAttribArray", offsetof(struct glfunctions, EnableVertexAttribArray), M},
    {"glFramebufferRenderbuffer", offsetof(struct glfunctions, FramebufferRenderbuffer), M},
    {"glFramebufferTexture2D", offsetof(struct glfunctions, FramebufferTexture2D), M},
    {"glGenBuffers", offsetof(struct glfunctions, GenBuffers), M},
    {"glGenFramebuffers", offsetof(struct glfunctions, GenFramebuffers), M},
    {"glGenRenderbuffers", offsetof(struct glfunctions, GenRenderbuffers), M},
    {"glGenTextures", offsetof(struct glfunctions, GenTextures), M},
    {"glGenVertexArrays", offsetof(struct glfunctions, GenVertexArrays), 0},
    {"glGenerateMipmap", offsetof(struct glfunctions, GenerateMipmap), M},
    {"glGetAttachedShaders", offsetof(struct glfunctions, GetAttachedShaders), M},
    {"glGetAttribLocation", offsetof(struct glfunctions, GetAttribLocation), M},
    {"glGetBooleanv", offsetof(struct glfunctions, GetBooleanv), M},
    {"glGetError", offsetof(struct glfunctions, GetError), M},
    {"glGetIntegerv", offsetof(struct glfunctions, GetIntegerv), M},
    {"glGetProgramInfoLog", offsetof(struct glfunctions, GetProgramInfoLog), M},
    {"glGetProgramiv", offsetof(struct glfunctions, GetProgramiv), M},
    {"glGetRenderbufferParameteriv", offsetof(struct glfunctions, GetRenderbufferParameteriv), M},
    {"glGetShaderInfoLog", offsetof(struct glfunctions, GetShaderInfoLog), M},
    {"glGetShaderSource", offsetof(struct glfunctions, GetShaderSource), M},
    {"glGetShaderiv", offsetof(struct glfunctions, GetShaderiv), M},
    {"glGetString", offsetof(struct glfunctions, GetString), M},
    {"glGetStringi", offsetof(struct glfunctions, GetStringi), M},
    {"glGetUniformLocation", offsetof(struct glfunctions, GetUniformLocation), M},
    {"glLinkProgram", offsetof(struct glfunctions, LinkProgram), M},
    {"glReadPixels", offsetof(struct glfunctions, ReadPixels), M},
    {"glReleaseShaderCompiler", offsetof(struct glfunctions, ReleaseShaderCompiler), M},
    {"glRenderbufferStorage", offsetof(struct glfunctions, RenderbufferStorage), M},
    {"glShaderBinary", offsetof(struct glfunctions, ShaderBinary), M},
    {"glShaderSource", offsetof(struct glfunctions, ShaderSource), M},
    {"glStencilFunc", offsetof(struct glfunctions, StencilFunc), M},
    {"glStencilFuncSeparate", offsetof(struct glfunctions, StencilFuncSeparate), M},
    {"glStencilMask", offsetof(struct glfunctions, StencilMask), M},
    {"glStencilMaskSeparate", offsetof(struct glfunctions, StencilMaskSeparate), M},
    {"glStencilOp", offsetof(struct glfunctions, StencilOp), M},
    {"glStencilOpSeparate", offsetof(struct glfunctions, StencilOpSeparate), M},
    {"glTexImage2D", offsetof(struct glfunctions, TexImage2D), M},
    {"glTexParameteri", offsetof(struct glfunctions, TexParameteri), M},
    {"glTexSubImage2D", offsetof(struct glfunctions, TexSubImage2D), M},
    {"glUniform1f", offsetof(struct glfunctions, Uniform1f), M},
    {"glUniform1fv", offsetof(struct glfunctions, Uniform1fv), M},
    {"glUniform1i", offsetof(struct glfunctions, Uniform1i), M},
    {"glUniform1iv", offsetof(struct glfunctions, Uniform1iv), M},
    {"glUniform2f", offsetof(struct glfunctions, Uniform2f), M},
    {"glUniform2fv", offsetof(struct glfunctions, Uniform2fv), M},
    {"glUniform2i", offsetof(struct glfunctions, Uniform2i), M},
    {"glUniform2iv", offsetof(struct glfunctions, Uniform2iv), M},
    {"glUniform3f", offsetof(struct glfunctions, Uniform3f), M},
    {"glUniform3fv", offsetof(struct glfunctions, Uniform3fv), M},
    {"glUniform3i", offsetof(struct glfunctions, Uniform3i), M},
    {"glUniform3iv", offsetof(struct glfunctions, Uniform3iv), M},
    {"glUniform4f", offsetof(struct glfunctions, Uniform4f), M},
    {"glUniform4fv", offsetof(struct glfunctions, Uniform4fv), M},
    {"glUniform4i", offsetof(struct glfunctions, Uniform4i), M},
    {"glUniform4iv", offsetof(struct glfunctions, Uniform4iv), M},
    {"glUniformMatrix2fv", offsetof(struct glfunctions, UniformMatrix2fv), M},
    {"glUniformMatrix3fv", offsetof(struct glfunctions, UniformMatrix3fv), M},
    {"glUniformMatrix4fv", offsetof(struct glfunctions, UniformMatrix4fv), M},
    {"glUseProgram", offsetof(struct glfunctions, UseProgram), M},
    {"glVertexAttribPointer", offsetof(struct glfunctions, VertexAttribPointer), M},
    {"glViewport", offsetof(struct glfunctions, Viewport), M},
};
