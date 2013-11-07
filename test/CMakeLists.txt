cmake_minimum_required(VERSION 2.8)

project(mtest)

enable_testing()

find_package (Threads)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/..)

link_directories(${CMAKE_SOURCE_DIR}/libs)

add_executable(mtest mtest.cpp ../source/Parser.cpp ../source/Arguments.cpp ../source/ModeAndValue.cpp)

target_link_libraries(mtest libgtest.a)

target_link_libraries(mtest ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME mtest COMMAND mtest)

