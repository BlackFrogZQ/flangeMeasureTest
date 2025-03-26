add_subdirectory(scheme)
aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(urlLib ${DIR_SYSTEM_SRCS})
target_link_libraries(urlLib urlSchemeLib)