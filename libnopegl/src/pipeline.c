/*
 * Copyright 2023 Matthieu Bouron <matthieu.bouron@gmail.com>
 * Copyright 2019-2022 GoPro Inc.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <string.h>

#include "gpu_ctx.h"
#include "log.h"
#include "memory.h"
#include "pipeline.h"
#include "buffer.h"
#include "type.h"
#include "utils.h"

int ngli_pipeline_layout_copy(struct pipeline_layout *dst, const struct pipeline_layout *src)
{
    dst->textures_desc = ngli_memdup(src->textures_desc, src->nb_textures * sizeof(*src->textures_desc));
    if (!dst->textures_desc)
        return NGL_ERROR_MEMORY;
    dst->nb_textures = src->nb_textures;

    dst->uniforms_desc = ngli_memdup(src->uniforms_desc, src->nb_uniforms * sizeof(*src->uniforms_desc));
    if (!dst->uniforms_desc)
        return NGL_ERROR_MEMORY;
    dst->nb_uniforms = src->nb_uniforms;

    dst->buffers_desc = ngli_memdup(src->buffers_desc, src->nb_buffers * sizeof(*src->buffers_desc));
    if (!dst->buffers_desc)
        return NGL_ERROR_MEMORY;
    dst->nb_buffers = src->nb_buffers;

    dst->attributes_desc = ngli_memdup(src->attributes_desc, src->nb_attributes * sizeof(*src->attributes_desc));
    if (!dst->attributes_desc)
        return NGL_ERROR_MEMORY;
    dst->nb_attributes = src->nb_attributes;

    return 0;
}

void ngli_pipeline_layout_reset(struct pipeline_layout *layout)
{
    ngli_freep(&layout->textures_desc);
    ngli_freep(&layout->uniforms_desc);
    ngli_freep(&layout->buffers_desc);
    ngli_freep(&layout->attributes_desc);
    memset(layout, 0, sizeof(*layout));
}

struct pipeline *ngli_pipeline_create(struct gpu_ctx *gpu_ctx)
{
    return gpu_ctx->cls->pipeline_create(gpu_ctx);
}

int ngli_pipeline_init(struct pipeline *s, const struct pipeline_params *params)
{
    return s->gpu_ctx->cls->pipeline_init(s, params);
}

int ngli_pipeline_set_resources(struct pipeline *s, const struct pipeline_resources *resources)
{
    return s->gpu_ctx->cls->pipeline_set_resources(s, resources);
}

int ngli_pipeline_update_attribute(struct pipeline *s, int index, const struct buffer *buffer)
{
    if (index == -1)
        return NGL_ERROR_NOT_FOUND;

    return s->gpu_ctx->cls->pipeline_update_attribute(s, index, buffer);
}

int ngli_pipeline_update_uniform(struct pipeline *s, int index, const void *value)
{
    if (index == -1)
        return NGL_ERROR_NOT_FOUND;

    return s->gpu_ctx->cls->pipeline_update_uniform(s, index, value);
}

int ngli_pipeline_update_texture(struct pipeline *s, int index, const struct texture *texture)
{
    if (index == -1)
        return NGL_ERROR_NOT_FOUND;

    return s->gpu_ctx->cls->pipeline_update_texture(s, index, texture);
}

int ngli_pipeline_update_buffer(struct pipeline *s, int index, const struct buffer *buffer, size_t offset, size_t size)
{
    if (index == -1)
        return NGL_ERROR_NOT_FOUND;

    return s->gpu_ctx->cls->pipeline_update_buffer(s, index, buffer, offset, size);
}

void ngli_pipeline_draw(struct pipeline *s, int nb_vertices, int nb_instances)
{
    s->gpu_ctx->cls->pipeline_draw(s, nb_vertices, nb_instances);
}

void ngli_pipeline_draw_indexed(struct pipeline *s, const struct buffer *indices, int indices_format, int nb_indices, int nb_instances)
{
    s->gpu_ctx->cls->pipeline_draw_indexed(s, indices, indices_format, nb_indices, nb_instances);
}

void ngli_pipeline_dispatch(struct pipeline *s, uint32_t nb_group_x, uint32_t nb_group_y, uint32_t nb_group_z)
{
    s->gpu_ctx->cls->pipeline_dispatch(s, nb_group_x, nb_group_y, nb_group_z);
}

void ngli_pipeline_freep(struct pipeline **sp)
{
    if (!*sp)
        return;
    (*sp)->gpu_ctx->cls->pipeline_freep(sp);
}
