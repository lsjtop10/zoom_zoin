#include <stdlib.h>
#include "timetable.h"
#include "settings.h"
#include "fun_data.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();
	
	//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����
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