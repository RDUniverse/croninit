cmake_minimum_required(VERSION 2.8)

project(croninit)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src)

set(FFEXE main.cpp src/OutputHandler.cpp src/Identifier.cpp src/Parser.cpp src/CrontabFileEditor.cpp src/Arguments.cpp src/ModeAndValue.cpp)

add_executable(croninit ${FFEXE})

add_subdirectory(test)

add_custom_target(pack)

add_custom_command(TARGET pack COMMAND mkdir package)

add_custom_command(TARGET pack COMMAND mkdir DEBIAN
			       COMMAND mkdir usr
			       WORKING_DIRECTORY package)

add_custom_command(TARGET pack COMMAND mkdir bin
                               WORKING_DIRECTORY package/usr)

add_custom_command(TARGET pack COMMAND cp croninit package/usr/bin)

add_custom_command(TARGET pack COMMAND echo "Package: croninit">>control
                               COMMAND echo "Version: 1.0">>control
			       COMMAND echo "Maintainer: Aleksey Syromyatnikov">>control
			       COMMAND echo "Architecture: i386">>control
			       COMMAND echo "Description: Makes work with cron easier">>control
			       COMMAND echo " Allows to maintain crontab file through">>control
			       COMMAND echo " command line commands">>control
                               WORKING_DIRECTORY package/DEBIAN)

add_custom_command(TARGET pack COMMAND dpkg-deb -b package .)

add_custom_command(TARGET pack COMMAND sudo rm -R package)