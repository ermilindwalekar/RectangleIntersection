cmake_minimum_required(VERSION 3.6)
project(core)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR} "*.cpp" "*.h")
add_library(core STATIC ${SOURCE_FILES})