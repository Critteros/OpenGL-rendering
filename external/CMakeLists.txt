cmake_minimum_required(VERSION 3.15)

# Include FetchContent API
include(FetchContent)

# Disable Warnings
include("../cmake/DisableWarnings.cmake")

# fmt
FetchContent_Declare(
        fmt
        GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
        GIT_TAG "d141cdbeb0fb422a3fb7173b285fd38e0d1772dc"
)

set(FMT_HEADER_ONLY TRUE)
FetchContent_MakeAvailable(fmt)
disable_project_warnings(fmt)

# spdlog 
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
        GIT_TAG "eb3220622e73a4889eee355ffa37972b3cac3df5"
)
FetchContent_MakeAvailable(spdlog)
disable_project_warnings(spdlog)

# glfw
FetchContent_Declare(
        glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw.git"
        GIT_TAG "7d5a16ce714f0b5f4efa3262de22e4d948851525"
)
set(GLFW_BUILD_EXAMPLES FALSE)
set(GLFW_BUILD_TESTS FALSE)
set(GLFW_BUILD_DOCS FALSE)
FetchContent_MakeAvailable(glfw)
disable_project_warnings(glfw)


# glad
add_subdirectory(glad)
disable_project_warnings(glad)