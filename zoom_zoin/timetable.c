#include "timetable.h"
#define _CRT_SECURE_NO_WARNINGS 


TimeTable* initializeTimeTable()
{
	TimeTable* tempTable = (TimeTable*)malloc(sizeof(TimeTable));

	tempTable->size = 0;
	tempTable->_head = 0;
	tempTable->_tail = 0;

	for (int i = 0; i < BUF_Size; i++)
	{
		tempTable->_Buf[i] = NULL;
	}
	return tempTable;
}

void enqueue(TimeTable* pThis, Class input)
{
	//Class를 할당받고 할당받은 Class 값 초기화
	Class* tempClass = (Class*)malloc(sizeof(Class));

	tempClass->name = (char*)malloc(sizeof(char) * strlen(input.name));
	strcpy(tempClass->name, input.name);
	
	tempClass->zoomAdd = (char*)malloc(sizeof(char) * strlen(input.zoomAdd));
	strcpy(tempClass->zoomAdd, input.zoomAdd);

	tempClass->startTime = input.startTime;

	pThis->_Buf[pThis->_tail] = tempClass;
	pThis->_tail++;
	pThis->size++;
}


Class* lookHead(TimeTable* pThis)
{
	return pThis->_Buf[pThis->_head];
}


void cutHead(TimeTable* pThis)
{
	free(pThis->_Buf[pThis->_head]);
	pThis->_Buf[pThis->_head] == NULL;
	pThis->size--;
	pThis->_head++;
}

Class* getNodeByIndex(TimeTable* pThis, int index)
{
	return pThis->_Buf[pThis->_head + index];
}

//input1이 input2보다 작으면 데이터를 스왑
static void swapNumberBySize(int* input1, int* input2)
{
	int tmp;
	tmp = *input1;
	if (*input1 > *input2)
	{
		*input1 = *input2;
		*input2 = tmp;
	}
}

static void swapStartTime(Class* input1, Class* input2)
{
	DateTime temp;
	temp = input1->startTime;
	input1->startTime = input2->startTime;
	input2->startTime = temp;
}

bool swapTimeTable(TimeTable* pThis, int index1, int index2)
{

	int target1 = index1;
	int target2 = index2;

	swapNumberBySize(&target1, &target2);

	if (target1 < 0 || target2 > pThis->size - 1)
	{
		return false;
	}

	target1 = target1 + pThis->_head;
	target2 = target2 + pThis->_head;

	Class* tmp = pThis->_Buf[target1];

	pThis->_Buf[target1] = pThis->_Buf[target2];
	pThis->_Buf[target2] = tmp;

	swapStartTime(pThis->_Buf[target1], pThis->_Buf[target2]);

	return true;
}

bool changeTimeTable(TimeTable* pThis, Class input, int index)
{
	if (index > pThis->size - 1)
	{
		return false;
	}

	Class* Target = getNodeByIndex(pThis, index);

	//copy data in input to target IF CLASS STRUCT ARE CHANGED, EDIT THIS
	free(Target->name);
	free(Target->zoomAdd);

	Target->name = malloc(sizeof(char) * strlen(input.name));
	strcpy(Target->name, input.name);

	Target->zoomAdd = malloc(sizeof(char) * strlen(input.zoomAdd));
	strcpy(Target->zoomAdd, input.zoomAdd);

	Target->startTime = input.startTime;

	return true;
}