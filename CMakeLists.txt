cmake_minimum_required(VERSION 3.17)

project(CGr LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

#Grouping manually enabled options
add_library(additional_options INTERFACE)
target_compile_features(additional_options INTERFACE cxx_std_17)

include(cmake/Conan.cmake)
run_conan()

#Compiler Warnings
include("cmake/CompilerWarnings.cmake")
set_project_warnings(additional_options)

# sanitizer options if supported by compiler
include("cmake/Sanitizers.cmake")
enable_sanitizers(additional_options)

include("cmake/StaticAnalyzers.cmake")

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

# Set up some extra Conan dependencies based on our needs before loading Conan
set(CONAN_EXTRA_REQUIRES "spdlog/1.9.0 fmt/8.0.1 glfw/3.3.6")
set(CONAN_EXTRA_OPTIONS "")

file(GLOB sources "src/*.cpp")


add_subdirectory("./vendor")

set(ENABLE_CLANG_TIDY ON)
add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

find_package(fmt REQUIRED)
target_link_libraries(${PROJECT_NAME} fmt::fmt)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

find_package(glfw3)
target_link_libraries(${PROJECT_NAME} glfw)

target_link_libraries(${PROJECT_NAME} glad)


target_link_libraries(${PROJECT_NAME} additional_options)



