add_subdirectory(hikrobotEngine)

aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(imageProcessLib ${DIR_SYSTEM_SRCS})

target_link_libraries(imageProcessLib
                    hikrobotEngineLib)