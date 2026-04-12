#ifndef GQF_SAMPLING_GLSL
#define GQF_SAMPLING_GLSL

vec4 sampleSafe(image2D img, ivec2 coord) {
    ivec2 size = imageSize(img);
    coord = clamp(coord, ivec2(0), size - 1);
    return imageLoad(img, coord);
}

vec4 sampleUV(sampler2D tex, vec2 uv) {
    return texture(tex, uv);
}

#endif
