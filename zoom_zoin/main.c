#include "settings.h"
#include "fun_data.h"
#include "timetable.h"


TimeTable* timeTable;

//void LoadTimeTableFromFile();
//void initlizeProgram(); //초반 작업
//void joinZoom()

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();

//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	Settings setting;

	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);


}

int main()
{
	initlizeProgram();

	shwoInitMenu();

	while (true)
	{

	}
}