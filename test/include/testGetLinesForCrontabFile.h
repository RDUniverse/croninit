TEST(CrontabFileEditor, getLinesForCrontabFile1GeneralTest) {
  std::vector<Arguments> vec;
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(EVERY, 0);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(EVERY, 0);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(EVERY, 0);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(EVERY, 0);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(INTERVAL, 3);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(INTERVAL, 3);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(INTERVAL, 3);
  ModeAndValue month(ONCE, 1);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(INTERVAL, 3);
  Arguments args(minute, hour, day, month);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(INTERVAL, 3);
  Arguments args(minute, hour, day, month);
  ModeAndValue minute2(ONCE, 6);
  ModeAndValue hour2(ONCE, 1);
  ModeAndValue day2(ONCE, 1);
  ModeAndValue month2(INTERVAL, 3);
  Arguments args2(minute2, hour2, day2, month2);
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
  ModeAndValue minute(ONCE, 1);
  ModeAndValue hour(ONCE, 1);
  ModeAndValue day(ONCE, 1);
  ModeAndValue month(INTERVAL, 3);
  Arguments args(minute, hour, day, month);
  ModeAndValue minute2(ONCE, 6);
  ModeAndValue hour2(ONCE, 1);
  ModeAndValue day2(ONCE, 1);
  ModeAndValue month2(INTERVAL, 3);
  Arguments args2(minute2, hour2, day2, month2);
  ModeAndValue minute3(ONCE, 6);
  ModeAndValue hour3(INTERVAL, 10);
  ModeAndValue day3(ONCE, 1);
  ModeAndValue month3(INTERVAL, 3);
  Arguments args3(minute3, hour3, day3, month3);
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
