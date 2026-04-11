cmake_minimum_required(VERSION 3.16)

project(ThemeDemo)

add_executable(theme_demo
    main.cpp
)

target_link_libraries(theme_demo
    myframework
)

target_include_directories(theme_demo PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
