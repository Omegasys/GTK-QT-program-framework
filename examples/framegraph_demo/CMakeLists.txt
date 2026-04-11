cmake_minimum_required(VERSION 3.16)
project(framegraph_demo)

set(CMAKE_CXX_STANDARD 20)

include_directories(../../include)

add_executable(framegraph_demo
    main.cpp
)

target_link_libraries(framegraph_demo
    GQFusion
)
