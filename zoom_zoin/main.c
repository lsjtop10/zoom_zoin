#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

TimeTable* timeTable;
Settings setting;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�
void joinZoom();

void initalizeProgram()
{
	timeTable = initializeTimeTable();

//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����

	//Setting Load
	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);
	



}

void test()
{
	initlizeProgram();
	showInitMenu(timeTable);

}