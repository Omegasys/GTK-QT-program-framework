#ifndef GQF_LAYOUT_GLSL
#define GQF_LAYOUT_GLSL

bool insideRect(vec2 p, vec2 pos, vec2 size) {
    return all(greaterThanEqual(p, pos)) &&
           all(lessThanEqual(p, pos + size));
}

vec2 localUV(vec2 p, vec2 pos, vec2 size) {
    return (p - pos) / size;
}

vec2 alignCenter(vec2 size, vec2 container) {
    return (container - size) * 0.5;
}

vec2 alignTopLeft(vec2 margin) {
    return margin;
}

vec2 alignBottomRight(vec2 size, vec2 container, vec2 margin) {
    return container - size - margin;
}

#endif
