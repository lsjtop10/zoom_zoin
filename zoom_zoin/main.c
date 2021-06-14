#include <stdlib.h>
#include "timetable.h"
#include "settings.h"
#include "fun_data.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //초반 작업

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();
	
	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현
	struct Settings setting;

	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);



}

void Test()
{

}

int main()
{
	initlizeProgram();

}