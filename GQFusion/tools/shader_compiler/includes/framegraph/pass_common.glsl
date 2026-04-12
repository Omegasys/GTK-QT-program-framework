#ifndef GQF_PASS_COMMON_GLSL
#define GQF_PASS_COMMON_GLSL

/*
 * Shared per-pass data
 */

layout(push_constant) uniform PassData {
    mat4 viewProj;
    vec2 resolution;
    float time;
    float deltaTime;
} uPass;

/*
 * Helpers
 */

vec2 getUV() {
    return gl_FragCoord.xy / uPass.resolution;
}

float getTime() {
    return uPass.time;
}

vec2 getResolution() {
    return uPass.resolution;
}

/*
 * Fullscreen triangle helper
 */

vec2 fullscreenTriangle(uint vertexID) {
    vec2 pos = vec2(
        (vertexID == 2u) ? 3.0 : -1.0,
        (vertexID == 1u) ? 3.0 : -1.0
    );
    return pos;
}

#endif
