cmake_minimum_required(VERSION 3.16)

project(ConfigEditorTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(CONFIG_EDITOR_SOURCES
    src/main.cpp
    src/ConfigEditorApp.cpp
    src/ConfigView.cpp
    src/ConfigTreeModel.cpp
    src/LivePreviewPanel.cpp

    src/ui/EditorWindow.cpp
    src/ui/TimeFrameEditor.cpp
    src/ui/ThemeSlotEditor.cpp
    src/ui/ColorPicker.cpp
)

# Executable
add_executable(config_editor ${CONFIG_EDITOR_SOURCES})

# Include paths
target_include_directories(config_editor PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link against your framework
target_link_libraries(config_editor PRIVATE myframework)

# Platform-specific handling (optional future expansion)
if (WIN32)
    target_compile_definitions(config_editor PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(config_editor PRIVATE PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(config_editor PRIVATE PLATFORM_LINUX)
endif()

# Enable warnings (good practice for tools)
if (MSVC)
    target_compile_options(config_editor PRIVATE /W4)
else()
    target_compile_options(config_editor PRIVATE -Wall -Wextra -Wpedantic)
endif()
