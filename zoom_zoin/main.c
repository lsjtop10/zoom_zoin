#include <stdlib.h>
#include "timetable.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();
	
	//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����
}

int main()
{
	initlizeProgram();

}