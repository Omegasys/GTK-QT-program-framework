cmake_minimum_required(VERSION 3.16)

project(ThemeEditorTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THEME_EDITOR_SOURCES
    src/main.cpp
    src/ThemeEditorApp.cpp

    src/ThemeCanvas.cpp
    src/GradientEditor.cpp
    src/ThemeTimelineView.cpp

    src/ui/ThemeWindow.cpp
    src/ui/ColorStopWidget.cpp
)

add_executable(theme_editor ${THEME_EDITOR_SOURCES})

target_include_directories(theme_editor PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(theme_editor PRIVATE myframework)

# Platform definitions (optional future expansion)
if (WIN32)
    target_compile_definitions(theme_editor PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(theme_editor PRIVATE PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(theme_editor PRIVATE PLATFORM_LINUX)
endif()

# Compiler warnings
if (MSVC)
    target_compile_options(theme_editor PRIVATE /W4)
else()
    target_compile_options(theme_editor PRIVATE -Wall -Wextra -Wpedantic)
endif()
