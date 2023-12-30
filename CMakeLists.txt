cmake_minimum_required(VERSION 3.20)

project(konkrete)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/main.cpp
    src/tokenization.cpp
    # Add more source files here
)

add_executable(kkt ${SOURCES} src/main.cpp)
