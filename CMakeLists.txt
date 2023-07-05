cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0091 NEW)

project(VTFLib C CXX)

option(VTFLIB_STATIC "If enabled, builds VTFLib as a static library" ON)
option(VTFLIB_SHARED "If enabled, builds VTFLib as a shared library" ON)

set(CMAKE_CXX_STANDARD 17)

include_directories(thirdparty/include thirdparty/miniz)

if (UNIX)
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
endif()

# MT/MTd specification for Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(VTFLib)
