cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER "C:/Program\ Files\ (x86)/CodeBlocks/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program\ Files\ (x86)/CodeBlocks/MinGW/bin/g++.exe")
set(GTEST_DISABLE_PTHREAD ON)

add_subdirectory(core)
add_subdirectory(googletest)
add_subdirectory(unittests)
add_subdirectory(solution)

target_compile_options(core PRIVATE -std=c++11)
target_compile_options(solution PRIVATE -std=c++11)
target_compile_options(unittests PRIVATE -std=gnu++0x)

target_include_directories(unittests PUBLIC ${CMAKE_SOURCE_DIR}/googletest/include)
target_include_directories(unittests PUBLIC ${CMAKE_SOURCE_DIR}/core)
target_include_directories(solution PUBLIC ${CMAKE_SOURCE_DIR}/core)