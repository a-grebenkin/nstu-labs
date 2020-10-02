cmake_minimum_required(VERSION 3.15)
project(nstu_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(nstu_lab main.cpp generators/BaseGenerator.cpp generators/BaseGenerator.h generators/GeneratorWithStep.cpp generators/GeneratorWithStep.h generators/RandomGenerator.cpp generators/RandomGenerator.h)