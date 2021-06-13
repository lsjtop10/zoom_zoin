#include "timetable.h"



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

	if (index <= 0 || index > pThis->size - 1)
	{
		return NULL;
	}

	for (int i = 0; i < index; i++)
	{
		horse = horse->next;
	}

	return horse;
}

//input1이 input2보다 작으면 데이터를 스왑
static void changeNumberBySize(int* input1, int* input2)
{
	int tmp;
	tmp = *input1;
	if (*input1 > *input2)
	{
		*input1 = *input2;
		*input2 = tmp;
	}
}

bool SwapTimeTable(TimeTable* pThis, int index1, int index2)
{

}

bool ChangeTimeTable(TimeTable* pThis, Class input, int index)
{
	if (index > pThis->size - 1)
	{
		return false;
	}

	Class* Target = getNodeByIndex(pThis, index);

	//copy data in input to target
	Target->name = input.name;
	Target->zoomAdd = input.zoomAdd;
	Target->startTime = input.startTime;

	return true;
}


