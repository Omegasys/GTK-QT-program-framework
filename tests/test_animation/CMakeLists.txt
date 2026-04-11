cmake_minimum_required(VERSION 3.16)

project(MyFrameworkAnimationTests)

add_executable(test_animation
    main.cpp
    test_easing.cpp
    test_timeline.cpp
    test_property_animation.cpp
)

target_link_libraries(test_animation
    myframework
)

target_include_directories(test_animation PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
