TEST(CrontabFileEditor, getLinesForCrontabFile1GeneralTest) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 1 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile2MinuteIsEvery) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 0;
  args.minute.mode = EVERY;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "* 1 1 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile3HourIsEvery) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 0;
  args.hour.mode = EVERY;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 * 1 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile4DayIsEvery) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 0;
  args.day.mode = EVERY;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 * 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile5MonthIsEvery) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 0;
  args.month.mode = EVERY;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 1 * * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile6MinuteIsInterval) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 3;
  args.minute.mode = INTERVAL;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "*/3 1 1 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile7HourIsInterval) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 3;
  args.hour.mode = INTERVAL;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 */3 1 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile8DayIsInterval) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 3;
  args.day.mode = INTERVAL;
  args.month.value = 1;
  args.month.mode = ONCE;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 */3 1 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile9MonthIsInterval) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 3;
  args.month.mode = INTERVAL;
  vec.push_back(args);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 1 */3 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile10TwoTasks) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 3;
  args.month.mode = INTERVAL;
  Arguments args2 = args;
  args2.minute.value = 6;
  vec.push_back(args);
  vec.push_back(args2);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 1 */3 * /usr/bin/ntpdate server\n6 1 1 */3 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}

TEST(CrontabFileEditor, getLinesForCrontabFile11ThreeTasks) {
  std::vector<Arguments> vec;
  Arguments args;
  args.minute.value = 1;
  args.minute.mode = ONCE;
  args.hour.value = 1;
  args.hour.mode = ONCE;
  args.day.value = 1;
  args.day.mode = ONCE;
  args.month.value = 3;
  args.month.mode = INTERVAL;
  Arguments args2 = args;
  args2.minute.value = 6;
  Arguments args3 = args2;
  args3.hour.value = 10;
  args3.hour.mode = INTERVAL;
  vec.push_back(args);
  vec.push_back(args2);
  vec.push_back(args3);
  std::string server = "server";
  std::string result;
  CrontabFileEditorMock ctfem;
  result = ctfem.getLinesForCrontabFileMock(vec, server);
  std::string expResult = "1 1 1 */3 * /usr/bin/ntpdate server\n6 1 1 */3 * /usr/bin/ntpdate server\n6 */10 1 */3 * /usr/bin/ntpdate server\n";
  EXPECT_EQ(result, expResult);
}
