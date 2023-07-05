#
# Compressonator
#
# HACK: messing with cmake variables to avoid running the main cmakelists of compressonator
set(PROJECT_SOURCE_DIR "${VTFLib_SOURCE_DIR}/thirdparty/compressonator")
add_subdirectory(compressonator/cmp_compressonatorlib)
target_include_directories(CMP_Compressonator INTERFACE "${PROJECT_SOURCE_DIR}/cmp_compressonatorlib")
set(PROJECT_SOURCE_DIR "${VTFLib_SOURCE_DIR}")

