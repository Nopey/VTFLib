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
target_link_libraries(VTFEdit PRIVATE DevIL HLLib "${USABLE_VTFLIB}")

# Enable CLR, we're written in Managed C++
set_target_properties(VTFEdit PROPERTIES COMMON_LANGUAGE_RUNTIME "")
set(VS_DOTNET_REFS mscorlib System  System.Data System.Drawing System.Windows.Forms System.XML)
set_target_properties(VTFEdit PROPERTIES VS_DOTNET_REFERENCES "${VS_DOTNET_REFS}")
set_target_properties(VTFEdit PROPERTIES VS_GLOBAL_ROOTNAMESPACE "VTFEdit")

target_sources(VTFEdit PRIVATE
	About.cpp
	About.h
	CAbout.resX
	app.ico
	BatchConvert.cpp
	BatchConvert.h
	CBatchConvert.resX
	DirectoryItemInfoManager.h
	resource.h
	Utility.h
	VMTCreate.cpp
	VMTCreate.h
	CVMTCreate.resX
	VMTFileUtility.h
	VTFEdit.cpp
	VTFEdit.h
	VTFEdit.rc
	CVTFEdit.resX
	VTFFileUtility.h
	VTFOptions.cpp
	VTFOptions.h
	CVTFOptions.resX
	WADConvert.cpp
	WADConvert.h
	CWADConvert.resX
)
