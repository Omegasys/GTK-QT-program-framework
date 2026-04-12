#ifndef GQF_MATH_GLSL
#define GQF_MATH_GLSL

float saturate(float x) {
    return clamp(x, 0.0, 1.0);
}

vec2 saturate(vec2 v) {
    return clamp(v, vec2(0.0), vec2(1.0));
}

vec3 saturate(vec3 v) {
    return clamp(v, vec3(0.0), vec3(1.0));
}

float luminance(vec3 c) {
    return dot(c, vec3(0.299, 0.587, 0.114));
}

float remap(float v, float inMin, float inMax, float outMin, float outMax) {
    return outMin + (v - inMin) * (outMax - outMin) / (inMax - inMin);
}

float smoothMin(float a, float b, float k) {
    float h = max(k - abs(a - b), 0.0) / k;
    return min(a, b) - h * h * h * k * (1.0 / 6.0);
}

#endif
