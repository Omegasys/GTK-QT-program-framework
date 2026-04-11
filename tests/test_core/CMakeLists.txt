cmake_minimum_required(VERSION 3.16)

project(MyFrameworkCoreTests)

add_executable(test_core
    main.cpp
    test_object.cpp
    test_event_dispatcher.cpp
    test_signal_system.cpp
    test_timer.cpp
    test_logger.cpp
)

target_link_libraries(test_core
    myframework
)

target_include_directories(test_core PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
