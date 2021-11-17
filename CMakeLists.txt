cmake_minimum_required(VERSION 3.0)
project(AOP_Uebungen)

set(CMAKE_CXX_STANDARD 14)

add_executable(aol_uebungen main.cpp connector.h Menu.cpp euler/constants.h euler/EulerSolutions1_10.cpp euler/Eulerproblem.h euler/Eulerproblem.cpp service/SieveOfEratosthenes.cpp service/PrimeRepository.cpp Exercises.h aop/AOPExercises.cpp aop/AOPExercises.h aop/aopFibonacci.cpp aop/aopNullstellen.cpp aop/Fakultaet.cpp aop/aopHeronAlgorythm.cpp aop/aopCosinus.cpp service/SmallMathTools.cpp service/UserInteractions.cpp)
