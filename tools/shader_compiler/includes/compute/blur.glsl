#ifndef GQF_BLUR_GLSL
#define GQF_BLUR_GLSL

#include "sampling.glsl"

vec4 boxBlur(image2D img, ivec2 coord) {
    vec4 sum = vec4(0.0);

    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            sum += sampleSafe(img, coord + ivec2(x, y));
        }
    }

    return sum / 25.0;
}

vec4 gaussianBlur(image2D img, ivec2 coord) {
    float kernel[5] = float[](0.06, 0.24, 0.4, 0.24, 0.06);

    vec4 color = vec4(0.0);

    for (int i = -2; i <= 2; i++) {
        color += sampleSafe(img, coord + ivec2(i, 0)) * kernel[i + 2];
        color += sampleSafe(img, coord + ivec2(0, i)) * kernel[i + 2];
    }

    return color * 0.5;
}

#endif
