add_subdirectory(HIK3DMVS)

aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(cameraLib ${DIR_SYSTEM_SRCS})

target_link_libraries(cameraLib
            HIK3DMVSLib)