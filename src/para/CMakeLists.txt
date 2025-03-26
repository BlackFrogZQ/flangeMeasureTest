
add_library(paraLib "")
add_subdirectory(jsPara)

file(GLOB defineParas "define/*.cpp")
file(GLOB paraItems "define/paraItem/*.cpp")

add_library(paraBasicLib ${paraItems} ${defineParas} para.cpp)
target_link_libraries(paraLib paraBasicLib jsParaLib)