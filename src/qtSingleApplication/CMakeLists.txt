include_directories(lockedFile)
aux_source_directory(. DIR_SYSTEM_SRCS)
add_library(qtSingleApplicationLib ${DIR_SYSTEM_SRCS}  lockedFile/qtlocalpeer.cpp)
