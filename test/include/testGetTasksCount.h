TEST(Parser, GetTasksCount1NoTasks) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(1, targv1);
  parser.init();
  EXPECT_EQ(1, parser.getTasksCount());
}

TEST(Parser, GetTasksCount2OneTask) {
  const char *targv1c[] = {"program","--time","1/1","0:0"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  parser.init();
  EXPECT_EQ(1, parser.getTasksCount());
}

TEST(Parser, GetTasksCount3TwoTasks) {
  const char *targv1c[] = {"program","--time","1/1","0:0","--time","2/2","1:1"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  parser.init();
  EXPECT_EQ(2, parser.getTasksCount());
}

TEST(Parser, GetTasksCount4ThreeTasks) {
  const char *targv1c[] = {"program","--time","1/1","0:0","--time","2/2","1:1","--time","3/3","2:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  parser.init();
  EXPECT_EQ(3, parser.getTasksCount());
}  

TEST(Parser, GetTasksCount5ThreeTasksOneIsWrong) {
  const char *targv1c[] = {"program","--time","1/-1","0:0","--time","2/2","1:1","--time","3/3","2:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  parser.init();
  EXPECT_EQ(2, parser.getTasksCount());
}

TEST(Parser, GetTasksCount6ThreeTasksTwoAreWrong) {
  const char *targv1c[] = {"program","--time","1/-1","0:0","--time","2/-2","1:1","--time","3/3","2:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  parser.init();
  EXPECT_EQ(1, parser.getTasksCount());
}

TEST(Parser, GetTasksCount7ThreeTasksAllAreWrong) {
  const char *targv1c[] = {"program","--time","1/-1","0:0","--time","2/-2","1:1","--time","3/-3","2:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  parser.init();
  EXPECT_EQ(0, parser.getTasksCount());
}

TEST(Parser, GetTasksCount8NoTasksMistakes) {
  const char *targv1c[] = {"program","safdhsfgshjfhkff"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  parser.init();
  EXPECT_EQ(0, parser.getTasksCount());
}

TEST(Parser, GetTasksCount9FourTasks) {
  const char *targv1c[] = {"program","--time","1/1","0:0","--time","2/2","1:1","--time","3/3","2:2","--time","4/4","3:3"};
  char** targv1 = (char**) targv1c; 
  Parser parser(13, targv1);
  parser.init();
  EXPECT_EQ(4, parser.getTasksCount());
}

TEST(Parser, GetTasksCount10FiveTasks) {
  const char *targv1c[] = {"program","--time","1/1","0:0","--time","2/2","1:1","--time","3/3","2:2","--time","4/4","3:3","--time","5/5","4:4"};
  char** targv1 = (char**) targv1c; 
  Parser parser(16, targv1);
  parser.init();
  EXPECT_EQ(5, parser.getTasksCount());
}
