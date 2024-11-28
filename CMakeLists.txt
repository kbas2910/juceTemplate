cmake_minimum_required(VERSION 3.22)

project(juceTemplate)

set(CMAKE_CXX_STANDARD 20)

set(LIB_DIR ${CMAKE_BINARY_DIR}/libs)

include(cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GIT_TAG 8.0.2
    VERSION 8.0.2
    GITHUB_REPOSITORY juce-framework/JUCE
    SOURCE_DIR ${LIB_DIR}/juce
)

add_subdirectory(plugin)