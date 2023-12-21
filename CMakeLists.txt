cmake_minimum_required(VERSION 3.26)
project(X_O_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(X_O_game main.cpp GameManger.cpp Player.cpp RandomPlayer.cpp X_O_Board.cpp BoardGame_Classes.h)
