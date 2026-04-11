cmake_minimum_required(VERSION 3.16)
project(multi_window_demo)

set(CMAKE_CXX_STANDARD 20)

include_directories(../../include)

add_executable(multi_window_demo
    main.cpp
)

target_link_libraries(multi_window_demo
    GQFusion
)
