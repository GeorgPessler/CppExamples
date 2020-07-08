include_directories(${CMAKE_SOURCE_DIR}/lib)

set(fooappSrcs 
	main.cpp 
	process.cpp)
add_executable(fooapp 
	${fooappSrcs})

target_link_libraries(fooapp 
	util)

intall(TARGETS fooapp DESTINATION bin)
