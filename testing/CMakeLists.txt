cmake_minimum_required(VERSION 2.8)

project(mtest)

enable_testing()

find_package (Threads)

include_directories(/home/aleksey/gtest/include)

include_directories(/home/aleksey/projects/project2)

link_directories(/home/aleksey/gtest/include)

add_executable(mtest mtest.cpp ../Parser.cpp ../Arguments.cpp ../ModeAndValue.cpp)

target_link_libraries(mtest libgtest.a)

target_link_libraries(mtest ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME mtest COMMAND mtest)

