#ifndef GQF_PLATFORM_OPENGL_GLSL
#define GQF_PLATFORM_OPENGL_GLSL

#define GQF_BACKEND_OPENGL

/*
 * OpenGL ignores descriptor sets
 */

#define GQF_BINDING(set, binding) layout(binding = binding)

#define GQF_UNIFORM(set, binding, type, name) \
    layout(binding = binding) uniform type name;

#define GQF_SAMPLER2D(set, binding, name) \
    layout(binding = binding) uniform sampler2D name;

#define GQF_IMAGE2D(set, binding, format, name) \
    layout(binding = binding, format) uniform image2D name;

/*
 * Push constants fallback (use uniform block)
 */

#define GQF_PUSH_CONSTANT uniform

#endif
