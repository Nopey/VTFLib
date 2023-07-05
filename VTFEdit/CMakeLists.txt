#
# VTFEdit
# (Doesn't yet compile)
#

if(UNIX)
	return()
endif()

option(VTFEDIT "If enabled, builds VTFEdit" ON)
if(NOT VTFEDIT)
	return()
endif()

add_executable(VTFEdit WIN32)

target_precompile_headers(VTFEdit PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:${PROJECT_SOURCE_DIR}/VTFEdit/stdafx.h>")
target_link_libraries(VTFEdit PRIVATE DevIL "${USABLE_VTFLIB}")

# Enable CLR, we're written in Managed C++
set_target_properties(VTFEdit PROPERTIES COMMON_LANGUAGE_RUNTIME "")


target_sources(VTFEdit PRIVATE
	About.cpp
	About.h
	About.resX
	app.ico
	BatchConvert.cpp
	BatchConvert.h
	BatchConvert.resX
	DirectoryItemInfoManager.h
	resource.h
	Utility.h
	VMTCreate.cpp
	VMTCreate.h
	VMTCreate.resX
	VMTFileUtility.h
	VTFEdit.cpp
	VTFEdit.h
	VTFEdit.rc
	VTFEdit.resX
	VTFFileUtility.h
	VTFOptions.cpp
	VTFOptions.h
	VTFOptions.resx
	WADConvert.cpp
	WADConvert.h
	WADConvert.resX
)
