cmake_minimum_required(VERSION 3.16)

project(MyFrameworkThemeTests)

add_executable(test_theme
    main.cpp
    test_theme_parser.cpp
    test_theme_blending.cpp
    test_theme_scheduler.cpp
    test_theme_fallback.cpp
)

target_link_libraries(test_theme
    myframework
)

target_include_directories(test_theme PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
