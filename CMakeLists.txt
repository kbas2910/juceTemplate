cmake_minimum_required(VERSION 3.22)

project(juceTemplate
	VERSION 0.1
  	DESCRIPTION "A template to create a plugin with JUCE"
  	LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)

set_property(GLOBAL PROPERTY USE_FOLDERS YES)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

include(cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GIT_TAG 8.0.2
    VERSION 8.0.2
    GITHUB_REPOSITORY juce-framework/JUCE
    OPTIONS JUCE_ENABLE_MODULE_SOURCE_GROUPS ON
    SOURCE_DIR ${LIB_DIR}/juce
)

add_subdirectory(plugin)
