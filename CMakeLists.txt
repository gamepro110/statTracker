# global config
cmake_minimum_required(VERSION 3.16)

project(StatTracker)

# project wide defines
set(currentPreset ${CMAKE_BUILD_TYPE})

if(currentPreset STREQUAL "Debug")
    add_definitions(-DSTATS_DEBUG)
elseif(currentPreset STREQUAL "Release")
    add_definitions(-DSTATS_RELEASE)
elseif(currentPreset STREQUAL "MinSizeRel")
    add_definitions(-DSTATS_DIST)
endif()

if(WIN32)
    add_definitions(-DSTATS_WINDOWS)
    find_package(Vulkan REQUIRED)
elseif(UNIX)
    if(APPLE)
        add_definitions(-DSTATS_MACOS)
        find_package(Metal REQUIRED)
    else()
        add_definitions(-DSTATS_LINUX)
        find_package(Vulkan REQUIRED)
    endif()
else()
    message(FATAL_ERROR "unsuported platform")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
find_package(Doxygen REQUIRED)#dot mscgen dia)

set(vendorPath "${PROJECT_SOURCE_DIR}/vendor")

add_subdirectory(vendor)
add_subdirectory(core)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(tests)
add_subdirectory(docs)
