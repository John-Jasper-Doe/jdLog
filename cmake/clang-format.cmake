# additional target to perform clang-format run, requires clang-format

# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.hpp)
#foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
#    string(FIND ${SOURCE_FILE} ${PROJECT_TRDPARTY_DIR} PROJECT_TRDPARTY_DIR_FOUND)
#    if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
#        list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
#    endif ()
#endforeach ()

add_custom_target(
        clangformat
        COMMAND /usr/bin/clang-format-8
        -style=file    ##-style=LLVM
        -i
        ${ALL_SOURCE_FILES}
)
