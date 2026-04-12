#ifndef GQF_WORKGROUP_GLSL
#define GQF_WORKGROUP_GLSL

ivec2 globalID() {
    return ivec2(gl_GlobalInvocationID.xy);
}

ivec2 localID() {
    return ivec2(gl_LocalInvocationID.xy);
}

ivec2 workgroupID() {
    return ivec2(gl_WorkGroupID.xy);
}

#endif
