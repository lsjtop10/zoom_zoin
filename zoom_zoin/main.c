#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

TimeTable* timeTable;
Settings setting;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�
void joinZoom();

void test()
{
	timeTable = initializeTimeTable();

	DateTime tm;
	tm.tm_min = 00;
	tm.tm_hour = 9;
	Class sub = { "����(ä����)","https://zoom.us/j/5905372499?pwd=WE5nU0hMWXNzcThLZExnbXpKNThaZz09", tm };
	enqueue(timeTable,sub);

	tm.tm_hour = 10;

	Class sub2 = {"����(������)" ,"https://zoom.us/j/7076045025?pwd=U1dhWUJsNk1KN0tzeDNZbnJ3NktNZz09",tm };
	enqueue(timeTable, sub2);
	
	tm.tm_hour = 11;
	Class sub3 = {"����(���ξ�)","https://zoom.us/j/2235909214?pwd=aHRxUTlrblRYcGpwU2N2OHhBV2YwZz09",tm };
	enqueue(timeTable, sub3);

	showInitMenu(timeTable);
}

int main()
{
	test();
}