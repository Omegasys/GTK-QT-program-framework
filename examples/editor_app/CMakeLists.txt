cmake_minimum_required(VERSION 3.16)
project(editor_app)

set(CMAKE_CXX_STANDARD 20)

include_directories(../../include)

add_executable(editor_app
    main.cpp
)

target_link_libraries(editor_app
    GQFusion
)
