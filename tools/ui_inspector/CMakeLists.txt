cmake_minimum_required(VERSION 3.16)
project(ui_inspector)

set(CMAKE_CXX_STANDARD 20)

include_directories(../../include)

file(GLOB SRC_FILES
    src/*.cpp
    ui/*.cpp
)

add_executable(ui_inspector
    ${SRC_FILES}
)

target_link_libraries(ui_inspector
    GQFusion
)
