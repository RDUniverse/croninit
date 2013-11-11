cmake_minimum_required(VERSION 2.8)

project(croninit)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src)

set(FFEXE main.cpp src/OutputHandler.cpp src/Identifier.cpp src/Parser.cpp src/CrontabFileEditor.cpp src/Arguments.cpp src/ModeAndValue.cpp)

add_executable(croninit ${FFEXE})

add_subdirectory(test)
