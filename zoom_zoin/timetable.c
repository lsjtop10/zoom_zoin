#include "timetable.h"



TimeTable* initializeTimeTable()
{
	TimeTable* temptable = (TimeTable*)malloc(sizeof(TimeTable));
	temptable->_Head = temptable->_Tail = NULL;
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
		pThis->_Head = tempClass;
		pThis->size++;
		pThis->_Tail = tempClass;
	}
	else
	{
		pThis->_Tail->_next = tempClass;
		pThis->_Tail = pThis->_Tail->_next;
		pThis->size++;
	}

	pThis->_Tail = NULL;
}


Class* lookHead(TimeTable* pThis)
{
	return pThis->_Head;
}


void cutHead(TimeTable* pThis)
{
	if (pThis->size == 0)
	{
		return;
	}
	if (pThis->size == 1)
	{
		free(pThis->_Head);
		pThis->_Head = NULL;
		pThis->_Tail = NULL;
	}
	else
	{
		Class* next = pThis->_Head->_next;
		free(pThis->_Head);
		pThis->_Head = next;
	}
	pThis->size--;
}

Class* getNodeByIndex(TimeTable* pThis, int index)
{
	Class* horse;
	horse = pThis->_Head;

	if (index <= 0 || index > pThis->size - 1)
	{
		return NULL;
	}

	for (int i = 0; i < index; i++)
	{
		horse = horse->_next;
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

	//copy data in input to target IF CLASS STRUCT ARE CHANGED, EDIT THIS
	Target->name = input.name;
	Target->zoomAdd = input.zoomAdd;
	Target->startTime = input.startTime;

	return true;
}


