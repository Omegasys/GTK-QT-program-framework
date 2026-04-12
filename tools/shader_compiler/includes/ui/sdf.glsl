#ifndef GQF_SDF_GLSL
#define GQF_SDF_GLSL

float sdfCircle(vec2 p, float radius) {
    return length(p) - radius;
}

float sdfBox(vec2 p, vec2 size) {
    vec2 d = abs(p) - size;
    return length(max(d, 0.0)) + min(max(d.x, d.y), 0.0);
}

float sdfRoundedBox(vec2 p, vec2 size, float radius) {
    vec2 d = abs(p) - size + vec2(radius);
    return length(max(d, 0.0)) - radius;
}

float sdfSmooth(float dist, float edge) {
    return smoothstep(0.0, edge, -dist);
}

float sdfStroke(float dist, float width, float edge) {
    float outer = smoothstep(width + edge, width - edge, dist);
    float inner = smoothstep(-width + edge, -width - edge, dist);
    return outer - inner;
}

#endif
