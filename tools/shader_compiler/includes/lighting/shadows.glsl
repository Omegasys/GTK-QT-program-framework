#ifndef GQF_SHADOWS_GLSL
#define GQF_SHADOWS_GLSL

float simpleShadow(float depth, float shadowMapDepth, float bias) {
    return (depth - bias) > shadowMapDepth ? 0.0 : 1.0;
}

float softShadow(float depth, float shadowMapDepth, float bias, float softness) {
    float diff = depth - shadowMapDepth - bias;
    return clamp(1.0 - diff * softness, 0.0, 1.0);
}

#endif
