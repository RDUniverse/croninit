TEST(Parser, GetServerList1NoServers) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(1, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("NULL", str);
}

TEST(Parser, GetServerList2OneServer) {
  const char *targv1c[] = {"program","--server","someserver"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver", str);
}

TEST(Parser, GetServerList3TwoServersQuotationMarks) {
  const char *targv1c[] = {"program","--server","someserver1 someserver2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}

TEST(Parser, GetServerList4ThreeServersQuotationMarksAndSpaceRemoval) {
  const char *targv1c[] = {"program","--server","         someserver1    someserver2    someserver3   "};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2 someserver3", str);
}

TEST(Parser, GetServerList5ThreeServersQuatationMarksAndSpaceRemoval) {
  const char *targv1c[] = {"program","--server","         someserver1   someserver2      someserver3   someserver4  "};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2 someserver3 someserver4", str);
} 

TEST(Parser, GetServerList6TwoServersAndTime) {
  const char *targv1c[] = {"program","--server","someserver1 someserver2","--time","2/2","2:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}

TEST(Parser, GetServerList7TwoServersAndHelp) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(HELP, parser.init());
}

TEST(Parser, GetServerList8TwoServersAndGarbage) {
  const char *targv1c[] = {"program","--server","someserver1 someserver2","sdfmdkf","dsfhajf","fkdjfhjkfhkf"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}
