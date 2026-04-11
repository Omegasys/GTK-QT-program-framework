cmake_minimum_required(VERSION 3.16)

project(ConfigLiveReloadExample)

add_executable(config_live_reload
    main.cpp
)

target_link_libraries(config_live_reload
    myframework
)

target_include_directories(config_live_reload PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
