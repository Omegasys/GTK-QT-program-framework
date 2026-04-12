#ifndef GQF_UI_COMMON_GLSL
#define GQF_UI_COMMON_GLSL

vec4 applyOpacity(vec4 color, float opacity) {
    return vec4(color.rgb, color.a * opacity);
}

vec4 premultiplyAlpha(vec4 color) {
    return vec4(color.rgb * color.a, color.a);
}

vec4 blendNormal(vec4 base, vec4 overlay) {
    float a = overlay.a + base.a * (1.0 - overlay.a);
    vec3 rgb = (overlay.rgb * overlay.a +
               base.rgb * base.a * (1.0 - overlay.a)) / max(a, 1e-5);
    return vec4(rgb, a);
}

vec4 blendAdditive(vec4 a, vec4 b) {
    return vec4(a.rgb + b.rgb, max(a.a, b.a));
}

#endif
