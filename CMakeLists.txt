# For a general introduction to CMake, see:
# https://cmake.org/cmake/help/latest/guide/tutorial/

cmake_minimum_required(VERSION 3.14)
project(Aufgabenblatt_2)

# Use the C++20 standard; fail if the compiler does not support it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# External dependencies
#   This project uses OpenGL for rendering. find_package() searches for
#   libraries that are installed on your system. REQUIRED means CMake will
#   stop with an error if OpenGL is not found.
# ---------------------------------------------------------------------------
find_package(OpenGL REQUIRED)

# Make headers in external/ available to all targets via #include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)

# GLEW is an OpenGL extension loader. We compile it as part of our project
# rather than linking a shared library, so we define GLEW_STATIC.
add_definitions(-DGLEW_STATIC)

# ---------------------------------------------------------------------------
# GLFW - a library for creating windows and handling input
#   Instead of installing GLFW system-wide, we ship it in external/ and
#   build it from source using add_subdirectory().
# ---------------------------------------------------------------------------
set(GLFW_VERSION_DEPENDENT_DIRECTORY glfw-3.4)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/${GLFW_VERSION_DEPENDENT_DIRECTORY})

# ---------------------------------------------------------------------------
# NanoVG - a small vector graphics library used for 2D drawing
#   We compile it as a static library from a single C source file.
# ---------------------------------------------------------------------------
add_library(nanovg STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/external/nanovg/src/nanovg.c
)

# Suppress compiler warnings in third-party code that we do not maintain
if (CMAKE_COMPILER_IS_GNUCC)
  set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src/nanovg.c PROPERTIES COMPILE_FLAGS -Wno-unused-result)
elseif(MSVC)
  set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src/nanovg.c PROPERTIES COMPILE_FLAGS "/wd4005 /wd4456 /wd4457")
endif()

# Suppress deprecation warnings on Windows (MSVC-specific)
if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# ---------------------------------------------------------------------------
# Testing
#   enable_testing() activates CMake's test runner (ctest).
#   Individual tests are registered with add_test() in applications/CMakeLists.txt.
#   Run tests after building with:  ctest --build-config Release
# ---------------------------------------------------------------------------
enable_testing()

# ---------------------------------------------------------------------------
# Subdirectories
#   framework/    - reusable library code (shapes, math, window handling)
#   applications/ - the programs you build and run (example app + tests)
# ---------------------------------------------------------------------------
add_subdirectory(framework)
add_subdirectory(applications)
