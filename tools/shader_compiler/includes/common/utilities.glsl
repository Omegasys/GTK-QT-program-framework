#ifndef GQF_UTILITIES_GLSL
#define GQF_UTILITIES_GLSL

vec2 screenUV(vec2 fragCoord, vec2 resolution) {
    return fragCoord / resolution;
}

vec2 pixelToNDC(vec2 pixel, vec2 resolution) {
    return (pixel / resolution) * 2.0 - 1.0;
}

vec4 applyOpacity(vec4 color, float opacity) {
    return vec4(color.rgb, color.a * opacity);
}

vec3 gammaToLinear(vec3 c) {
    return pow(c, vec3(2.2));
}

vec3 linearToGamma(vec3 c) {
    return pow(c, vec3(1.0 / 2.2));
}

#endif
