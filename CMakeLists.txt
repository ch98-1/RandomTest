cmake_minimum_required (VERSION 2.6)
project (RandomTest)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(RandomTest c/Test.c c/Random.c)
