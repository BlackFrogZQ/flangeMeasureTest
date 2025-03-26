add_library(systemLogLib logDef.cpp)

add_library(debugLib debugLog.cpp)
add_library(releaseLib releaseLog.cpp)

target_link_libraries(systemLogLib
                        PRIVATE
						debug debugLib
						optimized releaseLib)