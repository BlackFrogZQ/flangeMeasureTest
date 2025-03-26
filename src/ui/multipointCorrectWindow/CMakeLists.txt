aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(multipointCorrectLib ${DIR_SYSTEM_SRCS})

target_link_libraries(multipointCorrectLib)