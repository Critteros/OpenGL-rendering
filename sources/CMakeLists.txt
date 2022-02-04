cmake_minimum_required(VERSION 3.15)

# Renderer target
file(GLOB_RECURSE renderer_src "renderer/*.cpp")
add_executable(renderer ${renderer_src})
target_link_libraries(renderer PRIVATE additional_options)
target_link_libraries(renderer PRIVATE fmt spdlog glfw glad)