# server config

file(
    GLOB_RECURSE
    Server_Src
    "src/*.cpp"
    "src/*.h"
)

add_executable(
    ServerSide
    ${Server_Src}
)

target_link_libraries(
    ServerSide
    PUBLIC
    CoreLib
)

target_include_directories(
    ServerSide
    PUBLIC
    "${PROJECT_SOURCE_DIR}/core/src/"
    "${Vulkan_INCLUDE_DIRS}"
)

set_target_properties(
    ServerSide
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    FOLDER "StatTracker"
)
