add_definitions( -D_ProjectName=\"${projectName}\")
add_subdirectory(camera)

aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(halLib ${DIR_SYSTEM_SRCS})

target_link_libraries(halLib
    cameraLib)