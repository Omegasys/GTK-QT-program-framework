#ifndef GQF_PLATFORM_METAL_GLSL
#define GQF_PLATFORM_METAL_GLSL

#define GQF_BACKEND_METAL

/*
 * Metal via SPIR-V cross typically maps bindings differently
 * Keep generic and remap in compiler stage
 */

#define GQF_BINDING(set, binding)

#define GQF_UNIFORM(set, binding, type, name) \
    uniform type name;

#define GQF_SAMPLER2D(set, binding, name) \
    uniform sampler2D name;

#define GQF_IMAGE2D(set, binding, format, name) \
    uniform image2D name;

/*
 * Push constants handled via buffers
 */

#define GQF_PUSH_CONSTANT uniform

#endif
