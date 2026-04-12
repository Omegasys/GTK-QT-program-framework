#ifndef GQF_PLATFORM_VULKAN_GLSL
#define GQF_PLATFORM_VULKAN_GLSL

#define GQF_BACKEND_VULKAN

/*
 * Vulkan uses descriptor sets + bindings
 */

#define GQF_BINDING(set, binding) layout(set = set, binding = binding)

#define GQF_UNIFORM(set, binding, type, name) \
    layout(set = set, binding = binding) uniform type name;

#define GQF_SAMPLER2D(set, binding, name) \
    layout(set = set, binding = binding) uniform sampler2D name;

#define GQF_IMAGE2D(set, binding, format, name) \
    layout(set = set, binding = binding, format) uniform image2D name;

#define GQF_PUSH_CONSTANT layout(push_constant)

#endif
