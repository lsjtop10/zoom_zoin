#include "timetable.h"
typedef struct tm DateTime;

TimeTable* initializeTimeTable()
{
	TimeTable* temptable = (TimeTable*)malloc(sizeof(TimeTable));
	temptable->Head = temptable->Tail = NULL;
	temptable->size = 0;
	return temptable;
}

void enqueue(TimeTable* timeTable, Class input)
{
	Class* tempClass = (Class*)malloc(sizeof(Class));
	tempClass->name = input.name;
	tempClass->zoomAdd = input.zoomAdd;
	tempClass->startTime = input.startTime;

	if (timeTable->size == 0)
	{
		timeTable->Head = tempClass;
		timeTable->size++;
		timeTable->Tail = tempClass;
	}
	else
	{
		timeTable->Tail->next = tempClass;
		timeTable->Tail = timeTable->Tail->next;
		timeTable->size++;
	}
}