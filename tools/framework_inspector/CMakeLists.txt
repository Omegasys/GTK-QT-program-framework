cmake_minimum_required(VERSION 3.16)

project(FrameworkInspectorTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INSPECTOR_SOURCES
    src/main.cpp
    src/InspectorApp.cpp
    src/WidgetTreeView.cpp
    src/PropertyEditor.cpp
    src/EventMonitor.cpp
    src/RenderDebugOverlay.cpp

    src/ui/InspectorWindow.cpp
    src/ui/LayoutDebugger.cpp
)

add_executable(framework_inspector ${INSPECTOR_SOURCES})

target_include_directories(framework_inspector PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(framework_inspector PRIVATE myframework)

# Platform definitions
if (WIN32)
    target_compile_definitions(framework_inspector PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(framework_inspector PRIVATE PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(framework_inspector PRIVATE PLATFORM_LINUX)
endif()

# Warnings
if (MSVC)
    target_compile_options(framework_inspector PRIVATE /W4)
else()
    target_compile_options(framework_inspector PRIVATE -Wall -Wextra -Wpedantic)
endif()
