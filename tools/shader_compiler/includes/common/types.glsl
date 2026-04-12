#ifndef GQF_TYPES_GLSL
#define GQF_TYPES_GLSL

struct Rect {
    vec2 position;
    vec2 size;
};

struct Color {
    vec4 rgba;
};

struct Transform2D {
    vec2 position;
    float rotation;
    vec2 scale;
};

struct Vertex2D {
    vec2 position;
    vec2 uv;
    vec4 color;
};

#endif
