cmake_minimum_required(VERSION 3.14)

#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "-std=c++14")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(example)

include_directories(${CMAKE_SOURCE_DIR}/lib/glfw)

set(src main.cpp)

add_executable(example ${src})
target_link_libraries(example ${CMAKE_SOURCE_DIR}/lib/glfw/lib-vc2019/glfw3.lib)

install(TARGETS example DESTINATION bin)
