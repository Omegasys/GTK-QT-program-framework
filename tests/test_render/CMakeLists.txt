cmake_minimum_required(VERSION 3.16)

project(MyFrameworkRenderTests)

add_executable(test_render
    main.cpp
    test_renderer.cpp
    test_draw_commands.cpp
    test_render_target.cpp
    test_shader_pipeline.cpp
    test_texture_upload.cpp
)

target_link_libraries(test_render
    myframework
)

target_include_directories(test_render PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
