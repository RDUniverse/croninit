include_directories(${CMAKE_SOURCE_DIR}/test/include)

link_directories(${CMAKE_SOURCE_DIR}/test/libs)

find_package(Threads)

set(LIBS libgtest.a ${CMAKE_THREAD_LIBS_INIT})

set(PARSER ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

add_executable(testInit testInit.cpp ${PARSER})

target_link_libraries(testInit ${LIBS})

add_test(NAME testInit COMMAND testInit)

add_executable(testGetServerList testGetServerList.cpp ${PARSER})

target_link_libraries(testGetServerList ${LIBS})

add_test(NAME testGetServerList COMMAND testGetServerList)

add_executable(testGetTask testGetTask.cpp ${PARSER})

target_link_libraries(testGetTask ${LIBS})

add_test(NAME testGetTask COMMAND testGetTask)

add_executable(testGetTasksCount testGetTasksCount.cpp ${PARSER})

target_link_libraries(testGetTasksCount ${LIBS})

add_test(NAME testGetTasksCount COMMAND testGetTasksCount)

add_executable(testSetTimeInCrontabFile testSetTimeInCrontabFile.cpp ${PARSER})

target_link_libraries(testSetTimeInCrontabFile ${LIBS})

add_test(NAME testSetTimeInCrontabFile COMMAND testSetTimeInCrontabFile)

add_executable(testAddServer testAddServer.cpp ${PARSER})

target_link_libraries(testAddServer ${LIBS})

add_test(NAME testAddServer COMMAND testAddServer)

add_executable(testGetLinesForCrontabFile testGetLinesForCrontabFile.cpp ../src/CrontabFileEditor.cpp ${PARSER})

target_link_libraries(testGetLinesForCrontabFile ${LIBS})

add_test(NAME testGetLinesForCrontabFile COMMAND testGetLinesForCrontabFile)

add_custom_target(tests)

add_dependencies(tests testAddServer testSetTimeInCrontabFile testAddServer testInit testGetTasksCount testGetServerList testGetLinesForCrontabFile)
