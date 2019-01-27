cmake_minimum_required(VERSION 2.8)

find_program(CMAKE_C_COMPILER NAMES $ENV{CC} gcc PATHS ENV PATH NO_DEFAULT_PATH)
find_program(CMAKE_CXX_COMPILER NAMES $ENV{CXX} g++ PATHS ENV PATH NO_DEFAULT_PATH)

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