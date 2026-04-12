#ifndef GQF_GLOW_GLSL
#define GQF_GLOW_GLSL

float extractBright(vec3 color, float threshold) {
    float brightness = dot(color, vec3(0.299, 0.587, 0.114));
    return max(brightness - threshold, 0.0);
}

vec3 applyGlow(vec3 base, vec3 glow, float intensity) {
    return base + glow * intensity;
}

#endif
