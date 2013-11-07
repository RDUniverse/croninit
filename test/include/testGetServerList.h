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

TEST(Parser, GetServerList3TwoServers) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}

TEST(Parser, GetServerList4ThreeServers) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2","--server","someserver3"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2 someserver3", str);
}

TEST(Parser, GetServerList5ThreeServers) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2","--server","someserver3","--server","someserver4"};
  char** targv1 = (char**) targv1c; 
  Parser parser(9, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2 someserver3 someserver4", str);
} 

TEST(Parser, GetServerList6TwoServersAndTaskInTheMiddle) {
  const char *targv1c[] = {"program","--server","someserver1","--time","2/2","2:2","--server","someserver2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(8, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}

TEST(Parser, GetServerList7TwoServersAndHelp) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, GetServerList8TwoServersAndGarbage) {
  const char *targv1c[] = {"program","--server","someserver1","sdfmdkf","dsfhajf","fkdjfhjkfhkf","--server","someserver2","safjdadhjadm"};
  char** targv1 = (char**) targv1c; 
  Parser parser(9, targv1);
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
}
