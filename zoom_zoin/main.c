#include "settings.h"
#include "fun_data.h"
#include "timetable.h"


TimeTable* timeTable;

//void LoadTimeTableFromFile();
//void initlizeProgram(); //�ʹ� �۾�
//void joinZoom()

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();

//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����

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