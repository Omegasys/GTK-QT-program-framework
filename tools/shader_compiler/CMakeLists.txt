cmake_minimum_required(VERSION 3.16)

project(shader_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SHADER_COMPILER_SOURCES
    src/main.cpp
    src/ShaderCompiler.cpp
    src/GLSLParser.cpp
    src/ShaderIR.cpp
    src/OptimizationPass.cpp

    backends/VulkanCompiler.cpp
    backends/OpenGLCompiler.cpp
    backends/MetalCompiler.cpp
)

add_executable(shader_compiler ${SHADER_COMPILER_SOURCES})

target_include_directories(shader_compiler PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Optional framework linking (future GPU integration)
# target_link_libraries(shader_compiler PRIVATE myframework)

if (MSVC)
    target_compile_options(shader_compiler PRIVATE /W4)
else()
    target_compile_options(shader_compiler PRIVATE -Wall -Wextra -Wpedantic)
endif()
