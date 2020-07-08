cmake_minimum_required(VERSION 3.14)

project(UniquePointers)

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(src main.cpp)

add_executable(UniquePointers ${src})

install(TARGETS UniquePointers DESTINATION bin)
