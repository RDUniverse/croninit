include_directories(${CMAKE_SOURCE_DIR}/test/include)

link_directories(${CMAKE_SOURCE_DIR}/test/libs)

find_package(Threads)

add_executable(testInit testInit.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testInit libgtest.a)

target_link_libraries(testInit ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testInit COMMAND testInit)

add_executable(testGetServerList testGetServerList.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetServerList libgtest.a)

target_link_libraries(testGetServerList ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetServerList COMMAND testGetServerList)

add_executable(testGetTask testGetTask.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTask libgtest.a)

target_link_libraries(testGetTask ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTask COMMAND testGetTask)

add_executable(testGetTasksCount testGetTasksCount.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTasksCount libgtest.a)

target_link_libraries(testGetTasksCount ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTasksCount COMMAND testGetTasksCount)

add_executable(testSetTimeInCrontabFile testSetTimeInCrontabFile.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testSetTimeInCrontabFile libgtest.a)

target_link_libraries(testSetTimeInCrontabFile ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testSetTimeInCrontabFile COMMAND testSetTimeInCrontabFile)

add_executable(testAddServer testAddServer.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testAddServer libgtest.a)

target_link_libraries(testAddServer ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testAddServer COMMAND testAddServer)

add_executable(testGetLinesForCrontabFile testGetLinesForCrontabFile.cpp ../src/CrontabFileEditor.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetLinesForCrontabFile libgtest.a)

target_link_libraries(testGetLinesForCrontabFile ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetLinesForCrontabFile COMMAND testGetLinesForCrontabFile)

add_custom_target(tests)

add_dependencies(tests testAddServer testSetTimeInCrontabFile testAddServer testInit testGetTasksCount testGetServerList testGetLinesForCrontabFile)
