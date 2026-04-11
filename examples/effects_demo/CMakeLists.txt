cmake_minimum_required(VERSION 3.16)

project(EffectsDemo)

add_executable(effects_demo
    main.cpp
)

target_link_libraries(effects_demo
    myframework
)

target_include_directories(effects_demo PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
