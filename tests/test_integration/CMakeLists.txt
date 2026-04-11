cmake_minimum_required(VERSION 3.16)

project(MyFrameworkIntegrationTests)

add_executable(test_integration
    main.cpp
    test_full_app_boot.cpp
    test_widget_render_pipeline.cpp
    test_theme_live_reload_ui.cpp
    test_multi_window_support.cpp
)

target_link_libraries(test_integration
    myframework
)

target_include_directories(test_integration PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
