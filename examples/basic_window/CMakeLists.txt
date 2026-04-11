cmake_minimum_required(VERSION 3.16)

project(BasicWindowExample)

add_executable(basic_window
    main.cpp
)

target_link_libraries(basic_window
    myframework
)

target_include_directories(basic_window PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
