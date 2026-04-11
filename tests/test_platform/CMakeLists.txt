cmake_minimum_required(VERSION 3.16)

project(MyFrameworkPlatformTests)

add_executable(test_platform
    main.cpp
    test_window_creation.cpp
    test_input_events.cpp
    test_backend_switching.cpp
)

target_link_libraries(test_platform
    myframework
)

target_include_directories(test_platform PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
