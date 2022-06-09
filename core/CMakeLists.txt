# core config

file(
    GLOB_RECURSE
    CoreLib_Src
    "src/*.cpp"
    "src/*.h"
)

add_library(
    CoreLib
    STATIC
    ${CoreLib_Src}
)

target_include_directories(
    CoreLib
    PUBLIC
    "${PROJECT_SOURCE_DIR}/core/src/"
)

target_link_libraries(
    CoreLib
    PUBLIC
    glfw
    IMGUI_LIB
    spdlog
)

set_target_properties(
    CoreLib
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    FOLDER "StatTracker"
)
