cmake_minimum_required(VERSION 3.14)

project(SharedPointers)

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(src main.cpp)

add_executable(SharedPointers ${src})

install(TARGETS SharedPointers DESTINATION bin)
