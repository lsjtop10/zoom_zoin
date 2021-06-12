#include "timetable.h"
typedef struct tm DateTime;


TimeTable* initializeTimeTable()
{
	TimeTable* temptable = (TimeTable*)malloc(sizeof(TimeTable));
	temptable->Head = temptable->Tail = NULL;
	temptable->size = 0;
	return temptable;
}

void enqueue(TimeTable* pThis, Class input)
{
	//Class를 할당받고 입력받은 input에 맞게 초기화
	Class* tempClass = (Class*)malloc(sizeof(Class));
	tempClass->name = input.name;
	tempClass->zoomAdd = input.zoomAdd;
	tempClass->startTime = input.startTime;

	if (pThis->size == 0)
	{
		pThis->Head = tempClass;
		pThis->size++;
		pThis->Tail = tempClass;
	}
	else
	{
		pThis->Tail->next = tempClass;
		pThis->Tail = pThis->Tail->next;
		pThis->size++;
	}
}

Class* lookHead(TimeTable* pThis)
{
	return pThis->Head;
}

void cutHead(TimeTable* pThis)
{
	if (pThis->size == 0)
	{
		return;
	}
	if (pThis->size == 1)
	{
		free(pThis->Head);
		pThis->Head = NULL;
		pThis->Tail = NULL;
	}
	else
	{
		Class* next = pThis->Head->next;
		free(pThis->Head);
		pThis->Head = next;
	}
	pThis->size--;
}

Class* getNodeByIndex(TimeTable* pThis, int index)
{
	Class* horse;
	horse = pThis->Head;

	for (int i = 0; i < index; i++)
	{
		horse = horse->next;
	}

	return horse;
}

