cmake_minimum_required(VERSION 3.14)
project(TicTacToeCLI)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Board.cpp src/Player.cpp)
add_executable(TicTacToeCLI ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)
add_subdirectory(UnitTests)