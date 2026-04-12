#ifndef GQF_RESOURCE_BINDINGS_GLSL
#define GQF_RESOURCE_BINDINGS_GLSL

/*
 * Unified resource binding macros
 * Backend-specific mapping handled in platform/*.glsl
 */

#ifndef GQF_BINDING
    #define GQF_BINDING(set, binding)
#endif

#ifndef GQF_UNIFORM
    #define GQF_UNIFORM(set, binding, type, name) \
        layout(set = set, binding = binding) uniform type name;
#endif

#ifndef GQF_SAMPLER2D
    #define GQF_SAMPLER2D(set, binding, name) \
        layout(set = set, binding = binding) uniform sampler2D name;
#endif

#ifndef GQF_IMAGE2D
    #define GQF_IMAGE2D(set, binding, format, name) \
        layout(set = set, binding = binding, format) uniform image2D name;
#endif

#ifndef GQF_STORAGE_BUFFER
    #define GQF_STORAGE_BUFFER(set, binding, type, name) \
        layout(std430, set = set, binding = binding) buffer name##_buffer { \
            type data[]; \
        } name;
#endif

/*
 * Common resource naming conventions
 */

#define FG_INPUT_TEXTURE(name, set, binding) \
    GQF_SAMPLER2D(set, binding, name)

#define FG_OUTPUT_IMAGE(name, set, binding, format) \
    GQF_IMAGE2D(set, binding, format, name)

#endif
