    # add_subdirectory(order)
aux_source_directory(. DIR_SYSTEM_SRCS)
set(cppFlie
    setParaWindow.cpp
    paraTree/paraEditor.cpp
    paraTree/paraModel.cpp
    paraTree/paraTreeDelegate.cpp
    )
add_library(setParaWindowLib ${cppFlie})
