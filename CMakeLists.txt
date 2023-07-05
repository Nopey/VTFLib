cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0091 NEW)

project(VTFLib C CXX)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
endif()
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(thirdparty)

add_subdirectory(VTFLib)
add_subdirectory(VTFCmd)
add_subdirectory(VTFEdit)
