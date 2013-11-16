TEST(Parser, AddServer1AllIsOk) {  
  std::string par = "server";
  ParserMock pm;
  EXPECT_EQ("server", pm.addServerMock(par));
}

TEST(Parser, AddServer2Twoservers) {  
  std::string par = "server1 server2";
  ParserMock pm;
  EXPECT_EQ("server1 server2", pm.addServerMock(par));
}

TEST(Parser, AddServer3ThreeServers) {  
  std::string par = "server1 server2 server3";
  ParserMock pm;
  EXPECT_EQ("server1 server2 server3", pm.addServerMock(par));
}

TEST(Parser, AddServer4FourServers) {  
  std::string par = "server1 server2 server3 server4";
  ParserMock pm;
  EXPECT_EQ("server1 server2 server3 server4", pm.addServerMock(par));
}

TEST(Parser, AddServer5TwoServersWithRandomSpaces) {  
  std::string par = " server1        server2     ";
  ParserMock pm;
  EXPECT_EQ("server1 server2", pm.addServerMock(par));
}

TEST(Parser, AddServer6ThreeServersWithRandomSpaces) {  
  std::string par = "   server1      server2       server3          ";
  ParserMock pm;
  EXPECT_EQ("server1 server2 server3", pm.addServerMock(par));
}
