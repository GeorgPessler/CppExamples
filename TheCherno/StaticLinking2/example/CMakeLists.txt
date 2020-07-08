cmake_minimum_required(VERSION 3.14)

#set(CMAKE_BUILD_TYPE Debug)

project(example)

include_directories(${CMAKE_SOURCE_DIR}/example/include)

set(src main.cpp)

add_executable(example ${src})
target_link_libraries(example ${CMAKE_SOURCE_DIR}/example/glfw3.lib)

install(TARGETS example DESTINATION bin)
