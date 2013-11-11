include_directories(${CMAKE_SOURCE_DIR}/test/include)

link_directories(${CMAKE_SOURCE_DIR}/test/libs)

find_package(Threads)

file(WRITE mtest.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest.cpp "#include \"Parser.h\"\n")
file(APPEND mtest.cpp "#include \"testInit.h\"\n\n")
file(APPEND mtest.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testInit mtest.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testInit libgtest.a)

target_link_libraries(testInit ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testInit COMMAND testInit)

file(WRITE mtest.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest.cpp "#include \"Parser.h\"\n")
file(APPEND mtest.cpp "#include \"testGetServerList.h\"\n\n")
file(APPEND mtest.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetServerList mtest.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetServerList libgtest.a)

target_link_libraries(testGetServerList ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetServerList COMMAND testGetServerList)

file(WRITE mtest.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest.cpp "#include \"Parser.h\"\n")
file(APPEND mtest.cpp "#include \"testGetTask.h\"\n\n")
file(APPEND mtest.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetTask mtest.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTask libgtest.a)

target_link_libraries(testGetTask ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTask COMMAND testGetServerList)

file(WRITE mtest.cpp "#include \"gtest/gtest.h\"\n")
file(APPEND mtest.cpp "#include \"Parser.h\"\n")
file(APPEND mtest.cpp "#include \"testGetTasksCount.h\"\n\n")
file(APPEND mtest.cpp "int main(int argc, char* argv[]) {\n")
file(APPEND mtest.cpp "  ::testing::InitGoogleTest(&argc,argv);\n")
file(APPEND mtest.cpp "  return RUN_ALL_TESTS();\n}\n")

add_executable(testGetTasksCount mtest.cpp ../src/Parser.cpp ../src/Arguments.cpp ../src/ModeAndValue.cpp)

target_link_libraries(testGetTasksCount libgtest.a)

target_link_libraries(testGetTasksCount ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME testGetTasksCount COMMAND testGetServerList)