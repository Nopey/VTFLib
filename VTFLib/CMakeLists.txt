#
# VTFLib
#

option(VTFLIB_SHARED "If enabled, builds VTFLib as a shared library" ON)
option(VTFLIB_STATIC "If enabled, builds VTFLib as a static library" OFF)

if(VTFLIB_STATIC)
	set(USABLE_VTFLIB VTFLib_static PARENT_SCOPE)
elseif(VTFLIB_SHARED)
	set(USABLE_VTFLIB VTFLib PARENT_SCOPE)
else()
	message(FATAL_ERROR "Please enable either VTFLIB_STATIC or VTFLIB_SHARED.")
endif()

set(VTFLIB_TARGETS)
if(VTFLIB_SHARED)
	add_library(VTFLib SHARED)
	list(APPEND VTFLIB_TARGETS VTFLib)
endif()
if(VTFLIB_STATIC)
	add_library(VTFLib_static STATIC)
	target_compile_definitions(VTFLib_static PUBLIC VTFLIB_STATIC)
	list(APPEND VTFLIB_TARGETS VTFLib_static)
endif()

foreach(VTFLIB ${VTFLIB_TARGETS})

target_compile_definitions("${VTFLIB}" PRIVATE VTFLIB_EXPORTS)
target_precompile_headers("${VTFLIB}" PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:${PROJECT_SOURCE_DIR}/VTFLib/stdafx.h>")
target_include_directories("${VTFLIB}" PRIVATE ${PROJECT_SOURCE_DIR}/thirdparty/miniz ${PROJECT_SOURCE_DIR}/thirdparty/include)
target_include_directories("${VTFLIB}" INTERFACE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries("${VTFLIB}" PRIVATE CMP_Compressonator)

# Link against runtime lib
if (UNIX)
	target_link_libraries("${VTFLIB}" PRIVATE pthread)
endif()

target_sources("${VTFLIB}" PRIVATE
	Resource.rc

	Error.cpp
	FileReader.cpp
	FileWriter.cpp
	Float16.cpp
	MemoryReader.cpp
	MemoryWriter.cpp
	Proc.cpp
	ProcReader.cpp
	ProcWriter.cpp
	VMTFile.cpp
	VMTGroupNode.cpp
	VMTIntegerNode.cpp
	VMTNode.cpp
	VMTSingleNode.cpp
	VMTStringNode.cpp
	VMTValueNode.cpp
	VMTWrapper.cpp
	VTFFile.cpp
	VTFLib.cpp
	VTFMathlib.cpp
	VTFWrapper.cpp

	# Miniz sources
	"${PROJECT_SOURCE_DIR}/thirdparty/miniz/miniz.c"
)

endforeach()
