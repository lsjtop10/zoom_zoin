#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //초반 작업
void joinZoom();

void initlizeProgram()
{
	timeTable = initializeTimeTable();
	DateTime dt;
	dt.tm_hour = 1;
	dt.tm_min = 0;
	Class lic = { "국어","zoom.ussdklafj;lkj;lkasdfj",  dt };
	Class math = { "수학","asdfjawefjio;efsajkl;sfd/dasl;fkjeo;ijf", dt };
	Class eng = { "영어","asdfjk;asdlfjka;eoijlsdafkj",  dt };
	Class phy = { "생명과학1", "afkl;je;oijasdl;kfj;lkj", dt };
	Class lic1 = { "물리학1","afjew;iojasdl;kfj;lijawef",  dt };
	Class math2 = { "지구과학1",";sdlakfja;weoijl;asdfkj", dt };
	Class eng3 = { "영어1","af;ilesj;ldkasfj;lkj",  dt };
	Class phy4 = { "7", "asl;fiejliksadfj;liawefj", dt };
	enqueue(timeTable, lic);
	enqueue(timeTable, math);
	enqueue(timeTable, eng);
	enqueue(timeTable, phy);
	enqueue(timeTable, lic1);
	enqueue(timeTable, math2);
	enqueue(timeTable, eng3);
	enqueue(timeTable, phy4);
}

void test()
{
	initlizeProgram();
	showInitMenu(timeTable);
}



int main()
{
	test();

}