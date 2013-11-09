TEST(Parser, GetTask1GetStandardTask) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(1, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(0, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(0, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(EVERY, tst.day.mode);
  EXPECT_EQ(EVERY, tst.month.mode);
}

TEST(Parser, GetTask2GetTask) {
  const char *targv1c[] = {"program","--time","12/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask3GetTaskMinuteIsEvery) {
  const char *targv1c[] = {"program","--time","12/12","12:every"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(EVERY, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask4GetTaskHourIsEvery) {
  const char *targv1c[] = {"program","--time","12/12","every:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(EVERY, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask5GetTaskDayIsEvery) {
  const char *targv1c[] = {"program","--time","12/every","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(EVERY, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask6GetTaskMonthIsEvery) {
  const char *targv1c[] = {"program","--time","every/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(EVERY, tst.month.mode);
}

TEST(Parser, GetTask7GetTaskInervalMinute) {
  const char *targv1c[] = {"program","--time","12/12","12:every{12}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(INTERVAL, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask8GetTaskIntervalHour) {
  const char *targv1c[] = {"program","--time","12/12","every{12}:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(INTERVAL, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask9GetTaskIntervalDay) {
  const char *targv1c[] = {"program","--time","12/every{12}","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(INTERVAL, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask2GetTaskIntervalMonth) {
  const char *targv1c[] = {"program","--time","every{12}/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(12, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(12, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(12, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(12, tst.month.value);
  EXPECT_EQ(INTERVAL, tst.month.mode);
}

TEST(Parser, GetTask11GetSecondTask) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--time","6/6","6:6"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(1,tst);
  EXPECT_EQ(6, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(6, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(6, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(6, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}

TEST(Parser, GetTask12GetThirdTask) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--time","6/6","6:6","--time","3/3","3:3"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(2,tst);
  EXPECT_EQ(3, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(3, tst.hour.value);
  EXPECT_EQ(ONCE, tst.hour.mode);
  EXPECT_EQ(3, tst.day.value);
  EXPECT_EQ(ONCE, tst.day.mode);
  EXPECT_EQ(3, tst.month.value);
  EXPECT_EQ(ONCE, tst.month.mode);
}
