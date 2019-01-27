cmake_minimum_required(VERSION 3.6)
project(solution)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR} "*.cpp" "*.h")
add_executable(solution ${SOURCE_FILES})

if(MSVC OR MSYS)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.lib)
endif()
if(MINGW)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a)
endif()
if(UNIX AND NOT APPLE)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a)
endif()

target_link_libraries(solution ${LIBS})
