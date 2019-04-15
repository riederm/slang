cmake_minimum_required (VERSION 2.9)

#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(Slang)


add_subdirectory(src)

