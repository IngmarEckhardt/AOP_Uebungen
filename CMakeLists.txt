cmake_minimum_required(VERSION 3.0)
project(AOP_Uebungen)

set(CMAKE_CXX_STANDARD 17)

add_executable(aol_uebungen main.cpp connector.h eulerMenu.cpp constants.h eulerOneToTen.cpp eulerElevenToTwenty.cpp)
#target_link_libraries(aol_uebungen stdc++fs)
