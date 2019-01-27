cmake_minimum_required(VERSION 3.6)
project(unittests)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR} "*.cpp" "*.h")
add_executable(unittests ${SOURCE_FILES})

if(MSVC OR MSYS)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.lib ${CMAKE_SOURCE_DIR}/googletest/libgtest.lib)
endif()
if(MINGW)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a ${CMAKE_SOURCE_DIR}/googletest/libgtest.a)
endif()
if(UNIX AND NOT APPLE)
    set(LIBS ${CMAKE_SOURCE_DIR}/core/libcore.a ${CMAKE_SOURCE_DIR}/googletest/libgtest.a)
endif()

target_link_libraries(unittests ${LIBS})
