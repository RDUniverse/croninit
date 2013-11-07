cmake_minimum_required(VERSION 2.8)

project(croninit)

include_directories(${CMAKE_SOURCE_DIR}/source)

set(FFEXE main.cpp source/Identifier.cpp source/Parser.cpp source/CrontabFileEditor.cpp source/Arguments.cpp source/ModeAndValue.cpp)

add_executable(croninit ${FFEXE})
