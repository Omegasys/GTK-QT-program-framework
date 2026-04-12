#ifndef GQF_LIGHTING_GLSL
#define GQF_LIGHTING_GLSL

#include "../common/constants.glsl"

vec3 lambert(vec3 albedo) {
    return albedo * INV_PI;
}

vec3 phong(vec3 lightDir, vec3 viewDir, vec3 normal, float shininess) {
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    return vec3(spec);
}

#endif
