project(DateConverter_lib)

set(HEADER_FILES
        Board.h
        Player.h
        )

set(SOURCE_FILES
        Board.cpp
        Player.cpp
        )

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})