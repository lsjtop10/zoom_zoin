#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�
void joinZoom();

void initlizeProgram()
{
	timeTable = initializeTimeTable();
	DateTime dt;
	dt.tm_hour = 1;
	dt.tm_min = 0;
	Class lic = { "����","zoom.ussdklafj;lkj;lkasdfj",  dt };
	Class math = { "����","asdfjawefjio;efsajkl;sfd/dasl;fkjeo;ijf", dt };
	Class eng = { "����","asdfjk;asdlfjka;eoijlsdafkj",  dt };
	Class phy = { "�������1", "afkl;je;oijasdl;kfj;lkj", dt };
	Class lic1 = { "������1","afjew;iojasdl;kfj;lijawef",  dt };
	Class math2 = { "��������1",";sdlakfja;weoijl;asdfkj", dt };
	Class eng3 = { "����1","af;ilesj;ldkasfj;lkj",  dt };
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