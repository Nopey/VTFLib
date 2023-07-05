#
# Thirdparty Libraries
#

# Compressonator
# HACK: messing with cmake variables to avoid running the main cmakelists of compressonator
set(PROJECT_SOURCE_DIR "${VTFLib_SOURCE_DIR}/thirdparty/compressonator")
add_subdirectory(compressonator/cmp_compressonatorlib)
target_include_directories(CMP_Compressonator INTERFACE "${PROJECT_SOURCE_DIR}/cmp_compressonatorlib")
set(PROJECT_SOURCE_DIR "${VTFLib_SOURCE_DIR}")

# DevIL
add_library(DevIL INTERFACE)
target_link_libraries(DevIL INTERFACE "${VTFLib_SOURCE_DIR}/thirdparty/lib/DevIL.lib")
target_include_directories(DevIL INTERFACE "${VTFLib_SOURCE_DIR}/thirdparty/include")

# ZLib for HLLib
add_subdirectory(zlib)

# HLLib
set(DEPENDENCY_ZLIB_BUILD_INCLUDE "${zlib_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/zlib")
set(DEPENDENCY_ZLIB_BUILD_INCLUDE "${DEPENDENCY_ZLIB_BUILD_INCLUDE}" CACHE PATH "Path to zlib include directory. (forced)" FORCE)
set(DEPENDENCY_ZLIB_LIBRARY zlibstatic CACHE STRING "Path to zlib library." FORCE)

add_subdirectory(hllib)
target_include_directories(HLLib INTERFACE "${VTFLib_SOURCE_DIR}/thirdparty/hllib/lib")