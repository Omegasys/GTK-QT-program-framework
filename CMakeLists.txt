cmake_minimum_required(VERSION 3.16)
project(MyFramework VERSION 1.0 LANGUAGES C CXX)

# -----------------------
# Project settings
# -----------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -----------------------
# Options
# -----------------------
option(BUILD_EXAMPLES "Build example applications" ON)
option(BUILD_TESTS "Build unit tests" ON)

# -----------------------
# Include directories
# -----------------------
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/third_party
)

# -----------------------
# Source files
# -----------------------
set(SOURCES
    src/Application.cpp
    src/Window.cpp
    src/Widget.cpp
    src/Button.cpp
    src/Layouts.cpp
    src/Signals.cpp
    src/platform/Linux.cpp
    src/platform/Windows.cpp
    src/platform/MacOS.cpp
)

# -----------------------
# Create library
# -----------------------
add_library(MyFramework STATIC ${SOURCES})
target_include_directories(MyFramework PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Platform-specific dependencies
if(WIN32)
    target_link_libraries(MyFramework PRIVATE user32 gdi32)  # Win32 GUI libraries
elseif(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(APPKIT_LIBRARY AppKit)
    target_link_libraries(MyFramework PRIVATE ${COCOA_LIBRARY} ${APPKIT_LIBRARY})
elseif(UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    add_definitions(${GTK3_CFLAGS_OTHER})
    target_link_libraries(MyFramework PRIVATE ${GTK3_LIBRARIES})
endif()

# -----------------------
# Examples
# -----------------------
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# -----------------------
# Tests
# -----------------------
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# -----------------------
# Installation rules
# -----------------------
install(TARGETS MyFramework
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/MyFramework
        DESTINATION include)
