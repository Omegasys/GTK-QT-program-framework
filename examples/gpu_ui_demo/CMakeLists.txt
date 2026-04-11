cmake_minimum_required(VERSION 3.16)
project(gpu_ui_demo)

set(CMAKE_CXX_STANDARD 20)

include_directories(../../include)

add_executable(gpu_ui_demo
    main.cpp
)

target_link_libraries(gpu_ui_demo
    GQFusion
)
