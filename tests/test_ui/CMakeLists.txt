cmake_minimum_required(VERSION 3.16)

project(MyFrameworkUITests)

add_executable(test_ui
    main.cpp
    test_widget_hierarchy.cpp
    test_layout_engine.cpp
    test_button_interaction.cpp
    test_label_rendering.cpp
    test_window_events.cpp
)

target_link_libraries(test_ui
    myframework
)

target_include_directories(test_ui PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
