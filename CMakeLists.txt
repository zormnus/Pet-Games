cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME petGames)
set(CMAKE_CXX_STANDARD 14)

project(${PROJECT_NAME})

add_executable(guessTheNumber guessTheNumber.cpp)
add_executable(hangman Hangman.cpp)
add_executable(madLib MadLib.cpp)
add_executable(lostFortune LostFortune.cpp)
add_executable(wordJumble WordJumble.cpp)