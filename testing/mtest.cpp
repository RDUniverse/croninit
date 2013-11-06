#include "gtest/gtest.h"
#include "Parser.h"

TEST(Parser, Init1NoArguments) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(1, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init2WrongCommand) {
  const char *targv1c[] = {"program","--test"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init3Garbage) {
  const char *targv1c[] = {"program", "kzjfnkjzfgbjfgsdhj"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init4NoArgumentsAttAll) {
  const char *targv1c[] = {0};
  char** targv1 = (char**) targv1c; 
  Parser parser(0, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init5NegativeNumberOfArguments) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(-100, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init6Help) {
  const char *targv1c[] = {"program","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init7HelpWithGarbage) {
  const char *targv1c[] = {"program","--help","sadhkjhadsk"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init8HelpWithGarbageOtherSide) {
  const char *targv1c[] = {"program","askjdhsakjdhkjdahkdj","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init9HelpWithALotOfGarbage) {
  const char *targv1c[] = {"program","sadasdasdsaffrerthh","fgsfdfjjfgg","dfgsgfdgdfg","--help","dsjfjdhfbnmf"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init10TwoHelps) {
  const char *targv1c[] = {"program","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init11ThreeHelps) {
  const char *targv1c[] = {"program","--help","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init12TenHelps) {
  const char *targv1c[] = {"program","--help","--help","--help","--help","--help","--help","--help","--help","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(11, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init13TenHelpsWithALotOfGarbage) {
  const char *targv1c[] = {"program","sadfad","--help","--help","--help","asdaggvxvcvwrf","--help","--help","opsadxc","--help","--help","--help","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(14, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init14ServerNoArgument) {
  const char *targv1c[] = {"program","--server"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init15ServerWithArgument) {
  const char *targv1c[] = {"program","--server","someserver"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init16ServerWithGarbage) {
  const char *targv1c[] = {"program","sadasafdf","--server","someserver"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init17ServerWithGarbageRightSide) {
  const char *targv1c[] = {"program","--server","someserver","afkgfajmk"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init18ServerWithALotOfGarbage) {
  const char *targv1c[] = {"program","sadfbcbnbmxzbk","--server","someserver","sadjbvnbcxmncjdj","nbvj8wwjsdk"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init19ServerWithArgumentAndWithHelp) {
  const char *targv1c[] = {"program","--server","someserver","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init20ServerWithArgumentAndWithTwoHelps) {
  const char *targv1c[] = {"program","--server","someserver","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init21ServerWithArgumentAndWithFiveHelps) {
  const char *targv1c[] = {"program","--server","someserver","--help","--help","--help","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(8, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init22ServerWithArgumentAndWithFiveHelpsScatteredAllAround) {
  const char *targv1c[] = {"program","--help","--help","--server","someserver","--help","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(8, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init23TwoServersOneWithArgumentAndOneWithout) {
  const char *targv1c[] = {"program","--server","someserver","--server"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init24TwoServersWithArguments) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init25FourServersWithArguments) {
  const char *targv1c[] = {"program","--server","someserver1","--server","someserver2","--server","someserver3","--server","someserver4"};
  char** targv1 = (char**) targv1c; 
  Parser parser(9, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init26FourServersWithArgumentsAndHelp) {
  const char *targv1c[] = {"program","--help","--server","someserver1","--server","someserver2","--server","someserver3","--server","someserver4"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init27TwoServersWithArgumentsOneArgumentIsActuallyHelpButItsOK) {
  const char *targv1c[] = {"program","--server","someserver","--server","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init28TwoServersWithArgumentsOneArgumentIsActuallyHelpButItsOKAndALotOfGarbage) {
  const char *targv1c[] = {"program","nmxcnkdjhdk","--server","someserver","sadjhakjhkj","--server","--help","sajdbmncxbchgjd"};
  char** targv1 = (char**) targv1c; 
  Parser parser(8, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init29TwoServersWithArgumentsAndHelpBetweenThem) {
  const char *targv1c[] = {"program","--server","someserver1","--help","--server","someserver2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init30TimeNoArguments) {
  const char *targv1c[] = {"program","--time"};
  char** targv1 = (char**) targv1c; 
  Parser parser(2, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init31TimeOneArguments) {
  const char *targv1c[] = {"program","--time","arg"};
  char** targv1 = (char**) targv1c; 
  Parser parser(3, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init32TimeWithTwoRandomArguments) {
  const char *targv1c[] = {"program","--time","asjadhsadmncm","sadsabccvcghj"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init33TimeWithTwoArgumentsFirstIsRightSecondNot) {
  const char *targv1c[] = {"program","--time","12/12","sadsabccvcghj"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init34TimeWithTwoArgumentsFirstIsNotRightSecondIs) {
  const char *targv1c[] = {"program","--time","asmndakdjhk","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init35TimeWithTwoCorrectArguments) {
  const char *targv1c[] = {"program","--time","12/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init36TimeWithTwoCorrectArgumentsAndHelp) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init37TimeWithTwoCorrectArgumentsAndHelpBeforeTime) {
  const char *targv1c[] = {"program","--help","--time","12/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(5, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init38TimeWithTwoCorrectArgumentsAndTwoHelps) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init39TimeWithTwoCorrectArgumentsAndFourScatteredHelps) {
  const char *targv1c[] = {"program","--help","--help","--time","12/12","12:12","--help","--help"};
  char** targv1 = (char**) targv1c; 
  Parser parser(8, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init40TimeWithTwoCorrectArgumentsAndHelpAndServer) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--help","--server","someserver"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init41TimeWithTwoCorrectArgumentsAndHelpAndServerWithoutArgument) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--help","--server"};
  char** targv1 = (char**) targv1c; 
  Parser parser(6, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init42TimeWithTwoCorrectArgumentsAndHelpAndTwoServers) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--help","--server","someserver1","--server","someserver2"};
  char** targv1 = (char**) targv1c;                                                                        
  Parser parser(9, targv1);                                                                                 
  EXPECT_EQ(0, parser.init());                                                                             
}                                                                                                          
                                                                                                           
TEST(Parser, Init43TimeWithTwoCorrectArgumentsAndHelpAndThreeServersScattered) {                           
  const char *targv1c[] = {"program","--server","someserver1","--time","12/12","12:12","--help","--server","someserver2","--server","someserver3"};
  char** targv1 = (char**) targv1c; 
  Parser parser(11, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init44TwoTimesWithTwoCorrectArgumentsEach) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--time","6/6","6:6"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init45ThreeTimesWithTwoCorrectArgumentsEach) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--time","6/6","6:6","--time","3/3","3:3"};
  char** targv1 = (char**) targv1c; 
  Parser parser(10, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init46TwoTimesWithTwoCorrectArgumentsEachAndTwoServersBetweenThemAndHelp) {
  const char *targv1c[] = {"program","--time","12/12","12:12","--server","someserver1","--server","someserver2","--time","6/6","6:6"};
  char** targv1 = (char**) targv1c; 
  Parser parser(11, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init47TimeWithTwoArgumentsGarbageInMonths) {
  const char *targv1c[] = {"program","--time","asdasdhkj/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init48TimeWithTwoArgumentsGarbageInDays) {
  const char *targv1c[] = {"program","--time","12/adasdaadad","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init49TimeWithTwoArgumentsGarbageInHours) {
  const char *targv1c[] = {"program","--time","12/12","jkdhasjdmb:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init50TimeWithTwoArgumentsGarbageInMinutes) {
  const char *targv1c[] = {"program","--time","12/12","12:saldakjdkdhk"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init51TimeWithTwoArgumentsFirstArgNoSlash) {
  const char *targv1c[] = {"program","--time","1212","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init52TimeWithTwoArgumentsSecongArgNoColon) {
  const char *targv1c[] = {"program","--time","12/12","1212"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init53TimeWithTwoArgumentsMonthIsZero) {
  const char *targv1c[] = {"program","--time","0/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init54TimeWithTwoArgumentsDayIsZero) {
  const char *targv1c[] = {"program","--time","12/0","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init55TimeWithTwoArgumentsHourIsZero) {
  const char *targv1c[] = {"program","--time","12/12","0:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init56TimeWithTwoArgumentsMinuteIsZero) {
  const char *targv1c[] = {"program","--time","12/12","12:0"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init57TimeWithTwoArgumentsMonthIsNegative) {
  const char *targv1c[] = {"program","--time","-1/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init58TimeWithTwoArgumentsDayIsNegative) {
  const char *targv1c[] = {"program","--time","12/-1","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init59TimeWithTwoArgumentsHourIsNegative) {
  const char *targv1c[] = {"program","--time","12/12","-1:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init60TimeWithTwoArgumentsMinuteIsNegative) {
  const char *targv1c[] = {"program","--time","12/12","12:-1"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init61TimeWithTwoArgumentsMinuteIsAbove59) {
  const char *targv1c[] = {"program","--time","12/12","12:70"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init62TimeWithTwoArgumentsHourIsAbove23) {
  const char *targv1c[] = {"program","--time","12/12","25:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init63TimeWithTwoArgumentsDayIsAbove31) {
  const char *targv1c[] = {"program","--time","12/35","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init64TimeWithTwoArgumentsMonthIsAbove12) {
  const char *targv1c[] = {"program","--time","14/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init65TimeWithTwoArgumentsMistakeInMonth) {
  const char *targv1c[] = {"program","--time","12a/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init66TimeWithTwoArgumentsMistakeInDay) {
  const char *targv1c[] = {"program","--time","12/1a2","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init67TimeWithTwoArgumentsMistakeInHour) {
  const char *targv1c[] = {"program","--time","12/12","12a:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init68TimeWithTwoArgumentsMistakeInMinute) {
  const char *targv1c[] = {"program","--time","12a/12","12:12a"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init69TimeWithTwoArgumentsMonthIsEvery) {
  const char *targv1c[] = {"program","--time","every/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init70TimeWithTwoArgumentsDayIsEvery) {
  const char *targv1c[] = {"program","--time","12/every","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init71TimeWithTwoArgumentsHourIsEvery) {
  const char *targv1c[] = {"program","--time","12/12","every:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init72TimeWithTwoArgumentsMinuteIsEvery) {
  const char *targv1c[] = {"program","--time","12/12","12:every"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init73TimeWithTwoArgumentsEverythingIsEvery) {
  const char *targv1c[] = {"program","--time","every/every","every:every"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init74TimeWithTwoArgumentsIntervalMinuteIsZero) {
  const char *targv1c[] = {"program","--time","12/12","12:every{0}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init75TimeWithTwoArgumentsIntervalHourIsZero) {
  const char *targv1c[] = {"program","--time","12/12","every{0}:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init76TimeWithTwoArgumentsIntervalDayIsZero) {
  const char *targv1c[] = {"program","--time","12/every{0}","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init77TimeWithTwoArgumentsIntervalMonthIsZero) {
  const char *targv1c[] = {"program","--time","every{0}/12","12:12"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init78TimeWithTwoArgumentsEveryIntervalIsCorrect) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init79TimeWithTwoArgumentsIntervalMonthIsGarbage) {
  const char *targv1c[] = {"program","--time","every{fkhskjfhsd}/every{2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init80TimeWithTwoArgumentsIntervalDayIsGarbage) {
  const char *targv1c[] = {"program","--time","every{2}/every{fshkjgfhjbjbfhfejgweyweuihwer}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init81TimeWithTwoArgumentsIntervalHourIsGarbage) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{sjskjfhksad}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init82TimeWithTwoArgumentsIntervalMinuteIsGarbage) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2}:every{nbfdfhcjfhgdjh}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init83TimeWithTwoArgumentsMistakeInIntervalMinute) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2}:every{2a}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init84TimeWithTwoArgumentsMistakeInIntervalHour) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2a}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init85TimeWithTwoArgumentsMistakeInIntervalDay) {
  const char *targv1c[] = {"program","--time","every{2}/every{2a}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init86TimeWithTwoArgumentsMistakeInIntervalMonth) {
  const char *targv1c[] = {"program","--time","every{2a}/every{2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init87TimeWithTwoArgumentsIntervalHourIsNegative) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{-2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init88TimeWithTwoArgumentsIntervalMinuteIsNegative) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2}:every{-2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init89TimeWithTwoArgumentsIntervalDayIsNegative) {
  const char *targv1c[] = {"program","--time","every{2}/every{-2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init90TimeWithTwoArgumentsIntervalMonthIsNegative) {
  const char *targv1c[] = {"program","--time","every{-2}/every{2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init91TimeWithTwoArgumentsIntervalHourAbove23) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{30}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init92TimeWithTwoArgumentsIntervalMinuteAbove59) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}","every{2}:every{70}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init93TimeWithTwoArgumentsIntervalDayAbove31) {
  const char *targv1c[] = {"program","--time","every{2}/every{35}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init94TimeWithTwoArgumentsIntervalMonthAbove12) {
  const char *targv1c[] = {"program","--time","every{15}/every{2}","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init95TimeWithTwoArgumentsFirstArgTwoSlashes) {
  const char *targv1c[] = {"program","--time","every{2}/every{2}/2","every{2}:every{2}"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init96TimeWithTwoArgumentsSecondArgTwoColons) {
  const char *targv1c[] = {"program","--time","every{15}/every{2}","every{2}:every{2}:2"};
  char** targv1 = (char**) targv1c; 
  Parser parser(4, targv1);
  EXPECT_EQ(1, parser.init());
}

TEST(Parser, Init97TwoTimesAdditionalTest1) {
  const char *targv1c[] = {"program","--time","1/18","23:2","--time","5/6","1:7"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init98TwoTimesAdditionalTest2) {
  const char *targv1c[] = {"program","--time","3/1","5:56","--time","7/5","10:8"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init99TwoTimesAdditionalTest3) {
  const char *targv1c[] = {"program","--time","9/22","10:10","--time","12/3","23:59"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

TEST(Parser, Init100TwoTimesAdditionalTest4) {
  const char *targv1c[] = {"program","--time","1/1","0:0","--time","12/31","23:59"};
  char** targv1 = (char**) targv1c; 
  Parser parser(7, targv1);
  EXPECT_EQ(0, parser.init());
}

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
  parser.init();
  std::string str="NULL";
  parser.getServerList(str);
  EXPECT_EQ("someserver1 someserver2", str);
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

TEST(Parser, GetTask1GetStandardTask) {
  const char *targv1c[] = {"program"};
  char** targv1 = (char**) targv1c; 
  Parser parser(1, targv1);
  parser.init();
  Arguments tst;
  parser.getTask(0,tst);
  EXPECT_EQ(0, tst.minute.value);
  EXPECT_EQ(ONCE, tst.minute.mode);
  EXPECT_EQ(2, tst.hour.value);
  EXPECT_EQ(INTERVAL, tst.hour.mode);
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

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
