cmake_minimum_required(VERSION 3.17)

# Project Initialization
project(OpenGLv2 LANGUAGES CXX)

# Setting Global Cmake variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")
set(ENABLE_CLANG_TIDY OFF)

# Global settings for cmake
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)
include(cmake/StaticAnalyzers.cmake)

#Grouping manually enabled options
add_library(additional_options INTERFACE)
target_compile_features(additional_options INTERFACE cxx_std_17)

# Setting up external deps
add_subdirectory("./external")

#Compiler Warnings
include("cmake/CompilerWarnings.cmake")
set_project_warnings(additional_options)

# sanitizer options if supported by compiler
include("cmake/Sanitizers.cmake")
enable_sanitizers(additional_options)


option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which is a good idea if any #define's change
  #
  # consider breaking this out per project as necessary
  target_precompile_headers(
    additional_options
    INTERFACE
    <vector>
    <string>
    <map>
    <utility>
    <algorithm>)
endif()

# Compilation targets
add_subdirectory("./sources")


