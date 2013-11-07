#include "gtest/gtest.h"
#include "Parser.h"
#include "testInit.h"
#include "testGetTasksCount.h"
#include "testGetServerList.h"
#include "testGetTask.h"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
