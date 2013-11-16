TEST(Parser, SetTimeInCrontabFile1AllIsOk) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0; 
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(0, res);
}

TEST(Parser, SetTimeInCrontabFile2AllIsNotOk) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:g3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile3MinuteIsNegative) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:-3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile4HourIsNegative) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "-3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile5DayIsNegative) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/-3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile6MonthIsNegative) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "-3/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile7DayIsZero) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/0";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile8MonthIsZero) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "0/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile9MinuteIs60) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:60";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile10HourIs24) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "24:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile11DayIs32) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/32";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile12MonthIs13) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "13/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile13MinuteIsAbove60) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:70";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile14HourIsAbove24) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "30:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile15DayIsAbove32) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/40";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile16MonthIsAbove13) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "20/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile17GarbageInMinute) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:asdasd";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile18GarbageInHour) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "sdfhdjdh:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile19GarbageInDay) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/asdhkdj";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile20GarbageInMonth) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "akljsdkjhkdj/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile21NumberAndGarbageInMinute) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:3asdasd";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile22NumberAndGarbageInHour) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3sdfhdjdh:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile23NumberAndGarbageInDay) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3asdhkdj";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile24NumberAndGarbageInMonth) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3akljsdkjhkdj/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile25FirstArgumentNoSlash) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "33";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile26SecondArgumentNoColon) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "33";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile27FirstArgumentTwoSlashes) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile28SecondArgumentTwoColons) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile29FirstArgumentThreeSlashes) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3/3/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile30SecondArgumentThreeColons) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:3:3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile31GarbageInMinuteInterval) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:every{asdasd}";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile32GarbageInHourInterval) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "every{sdfhdjdh}:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile33GarbageInDayInterval) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/every{asdhkdj}";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile34GarbageInMonthInterval) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{akljsdkjhkdj}/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile35AllInstances1) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "1/1";
  std::string par2 = "1:1";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(1, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(1, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(1, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(1, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile36AllInstancesMax) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "12/31";
  std::string par2 = "23:59";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(59, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(23, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(31, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile37AllInstancesInTheMiddle) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/15";
  std::string par2 = "12:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile38HourIsEvery) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/15";
  std::string par2 = "every:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(0, tst.hour.value);
  EXPECT_EQ(EVERY, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile39MinuteIsEvery) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/15";
  std::string par2 = "12:every";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(0, tst.minute.value);
  EXPECT_EQ(EVERY, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile40DayIsEvery) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/every";
  std::string par2 = "12:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(0, tst.day.value);
  EXPECT_EQ(EVERY, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile41MonthIsEvery) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every/15";
  std::string par2 = "12:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(0, tst.month.value);
  EXPECT_EQ(EVERY, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile42HourIsInterval3) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/15";
  std::string par2 = "every{3}:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(3, tst.hour.value);
  EXPECT_EQ(INTERVAL, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile43MinuteIsInterval3) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/15";
  std::string par2 = "12:every{3}";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(3, tst.minute.value);
  EXPECT_EQ(INTERVAL, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile44DayIsInterval3) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "6/every{3}";
  std::string par2 = "12:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(3, tst.day.value);
  EXPECT_EQ(INTERVAL, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile45MonthIsInterval3) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{3}/15";
  std::string par2 = "12:30";
  Arguments tst;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, tst);
  EXPECT_EQ(0, res);
  EXPECT_EQ(30, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(15, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(3, tst.month.value);
  EXPECT_EQ(INTERVAL, tst.month.mode);
}

TEST(Parser, SetTimeInCrontabFile46MinuteInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:every{0}";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile47HourInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "every{0}:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile48DayInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/every{asdhkdj}";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile49MonthInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{akljsdkjhkdj}/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile50MinuteNegativeIntervalIsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:every{-1}";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile51HourNegativeIntervalIsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "every{-1}:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile52DayNegativeInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/every{-1}";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile53MonthNegativeInterval0IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{-1}/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile54MinuteInterval60IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:every{60}";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile55HourInterval24IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "every{24}:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile56DayInterval32IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/every{32}";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile57MonthInterval13IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{13}/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile58MinuteIntervalAbove60IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "3:every{70}";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile59HourIntervalAbove24IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/3";
  std::string par2 = "every{30}:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile60DayIntervalAbove32IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "3/every{40}";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}

TEST(Parser, SetTimeInCrontabFile61MonthIntervalAbove13IsWrong) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c;
  std::string par1 = "every{20}/3";
  std::string par2 = "3:3";
  Arguments args;
  ParserMock pm(1, targv1);
  int res = 0;
  res = pm.setTimeInCrontabFileMock(par1, par2, args);
  EXPECT_EQ(1, res);
}
