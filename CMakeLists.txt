cmake_minimum_required(VERSION 3.10)

project(trashIRC2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")
add_compile_options("-Wall" "-Wextra" "-pedantic")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

include_directories(include)

add_executable(trashIRC2025 ${SOURCES} ${HEADERS})
