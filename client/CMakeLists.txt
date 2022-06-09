# client config

file(
    GLOB_RECURSE
    Client_Src
    "src/*.cpp"
    "src/*.h"
)

add_executable(
    ClientSide
    ${Client_Src}
)

target_link_libraries(
    ClientSide
    PUBLIC
    CoreLib
)

target_include_directories(
    ClientSide
    PUBLIC
    "${PROJECT_SOURCE_DIR}/core/src/"
)

set_target_properties(
    ClientSide
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    FOLDER "StatTracker"
)
