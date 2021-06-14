#include <stdlib.h>
#include "timetable.h"

TimeTable* timeTable;

void LoadTimeTableFromFile();
void initlizeProgram(); //초반 작업

void LoadTimeTableFromFile()
{
	timeTable = initializeTimeTable();
	
	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현
}

int main()
{
	initlizeProgram();

}