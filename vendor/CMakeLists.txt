# vendor config

add_subdirectory(spdlog)

set_target_properties(
    spdlog
    PROPERTIES
    FOLDER "deps"
)

add_subdirectory(GLFW)

file(
    GLOB
    ImGui_Src
    "${vendorPath}/dear-imgui/*.cpp"
    "${vendorPath}/dear-imgui/*.h"
    "${vendorPath}/dear-imgui/backends/imgui_impl_glfw.cpp"
    "${vendorPath}/dear-imgui/backends/imgui_impl_glfw.h"
)

if(WIN32)
    set(ImGui_Src "${ImGui_Src};${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.h;${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.cpp")
elseif(UNIX)
    if(APPLE)
        message("!! check included imgui files !!")
        message(">>> PRE ${ImGui_Src}")
        set(ImGui_Src "${ImGui_Src};${vendorPath}/dear-imgui/backends/imgui_impl_metal.h;${vendorPath}/dear-imgui/backends/imgui_impl_metal.mm")
        message(">>> POST ${ImGui_Src}")
    else()
        set(ImGui_Src "${ImGui_Src};${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.h;${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.cpp")
    endif()
endif()

add_library(
    IMGUI_LIB
    STATIC
    ${ImGui_Src}
)

target_include_directories(
    IMGUI_LIB
    PUBLIC
    "${vendorPath}/dear-imgui/"
    "${vendorPath}/GLFW/include"
    "${Vulkan_INCLUDE_DIRS}"
)

target_link_libraries(
    IMGUI_LIB
    PUBLIC
    "${Vulkan_LIBRARIES}"
)

set_target_properties(
    IMGUI_LIB
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 20
    FOLDER "deps/ImGui"
)
