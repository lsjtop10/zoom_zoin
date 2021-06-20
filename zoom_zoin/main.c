#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

TimeTable* timeTable;
Settings setting;

void LoadTimeTableFromFile();
void initlizeProgram(); //초반 작업
void joinZoom();

void initalizeProgram()
{
	timeTable = initializeTimeTable();

//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	//Setting Load
	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);
	



}

void test()
{
	initlizeProgram();
	showInitMenu(timeTable);

}