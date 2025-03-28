aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(HIK3DMVSLib ${DIR_SYSTEM_SRCS})

target_link_libraries(HIK3DMVSLib)