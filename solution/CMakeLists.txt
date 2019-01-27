cmake_minimum_required(VERSION 3.6)
project(solution)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR} "*.cpp" "*.h")
add_executable(solution ${SOURCE_FILES})

set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a)
target_link_libraries(solution ${LIBS})
