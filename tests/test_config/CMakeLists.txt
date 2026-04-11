cmake_minimum_required(VERSION 3.16)

project(MyFrameworkConfigTests)

add_executable(test_config
    main.cpp
    test_config_parser.cpp
    test_live_reload.cpp
    test_config_validation.cpp
    test_timeframe_parsing.cpp
)

target_link_libraries(test_config
    myframework
)

target_include_directories(test_config PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
