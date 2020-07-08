cmake_minimum_required(VERSION 3.14)

project(PlaceholderTypeSpecifiers)

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(src main.cpp)

add_executable(PlaceholderTypeSpecifiers ${src})

install(TARGETS PlaceholderTypeSpecifiers DESTINATION bin)
