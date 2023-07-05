#
# VTFCmd
#

option(VTFCMD "If enabled, builds VTFCmd" OFF)
if(NOT VTFCMD)
	return()
endif()

add_executable(VTFCmd)

target_precompile_headers(VTFCmd PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:${PROJECT_SOURCE_DIR}/VTFCmd/stdafx.h>")
target_link_libraries(VTFCmd PRIVATE DevIL "${USABLE_VTFLIB}")


target_sources(VTFCmd PRIVATE
	VTFCmd.rc

	enumerations.c
	enumerations.h
	resource.h
	vtfcmd.c
)

set_source_files_properties(
	enumerations.c
	vtfcmd.c

	PROPERTIES
	LANGUAGE CXX
)
