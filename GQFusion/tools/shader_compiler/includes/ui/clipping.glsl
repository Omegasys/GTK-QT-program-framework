#ifndef GQF_CLIPPING_GLSL
#define GQF_CLIPPING_GLSL

float clipRect(vec2 p, vec2 minC, vec2 maxC) {
    return step(minC.x, p.x) *
           step(minC.y, p.y) *
           step(p.x, maxC.x) *
           step(p.y, maxC.y);
}

float clipRoundedRect(vec2 p, vec2 center, vec2 size, float radius) {
    vec2 d = abs(p - center) - size + vec2(radius);
    float dist = length(max(d, 0.0)) - radius;
    return step(dist, 0.0);
}

float clipSoft(float dist, float softness) {
    return smoothstep(softness, 0.0, dist);
}

#endif
