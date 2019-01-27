cmake_minimum_required(VERSION 3.6)
project(unittests)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR} "*.cpp" "*.h")
add_executable(unittests ${SOURCE_FILES})

set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a ${CMAKE_SOURCE_DIR}/googletest/libgtest.a)
target_link_libraries(unittests ${LIBS})
