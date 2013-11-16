include_directories(${CMAKE_SOURCE_DIR}/test/include)

link_directories(${CMAKE_SOURCE_DIR}/test/libs)

find_package(Threads)

file(WRITE mtest1.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest1.cpp "#include \"Parser.h\"\n")
file(APPEND mtest1.cpp "#include \"testInit.h\"\n\n")
file(APPEND mtest1.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest1.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest1.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testInit mtest1.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testInit libgtest.a)

target_link_libraries(testInit ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testInit COMMAND testInit)

file(WRITE mtest2.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest2.cpp "#include \"Parser.h\"\n")
file(APPEND mtest2.cpp "#include \"testGetServerList.h\"\n\n")
file(APPEND mtest2.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest2.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest2.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetServerList mtest2.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetServerList libgtest.a)

target_link_libraries(testGetServerList ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetServerList COMMAND testGetServerList)

file(WRITE mtest3.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest3.cpp "#include \"Parser.h\"\n")
file(APPEND mtest3.cpp "#include \"testGetTask.h\"\n\n")
file(APPEND mtest3.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest3.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest3.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetTask mtest3.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTask libgtest.a)

target_link_libraries(testGetTask ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTask COMMAND testGetTask)

file(WRITE mtest4.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest4.cpp "#include \"Parser.h\"\n")
file(APPEND mtest4.cpp "#include \"testGetTasksCount.h\"\n\n")
file(APPEND mtest4.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest4.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest4.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetTasksCount mtest4.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTasksCount libgtest.a)

target_link_libraries(testGetTasksCount ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTasksCount COMMAND testGetTasksCount)

file(WRITE mtest.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest.cpp "#include \"ParserMock.h\"\n")
file(APPEND mtest.cpp "#include \"testSetTimeInCrontabFile.h\"\n\n")
file(APPEND mtest.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testSetTimeInCrontabFile mtest.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testSetTimeInCrontabFile libgtest.a)

target_link_libraries(testSetTimeInCrontabFile ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testSetTimeInCrontabFile COMMAND testSetTimeInCrontabFile)
