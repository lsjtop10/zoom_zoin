#include "timetable.h"


Timetable* initialize_timetable()
{
	Timetable* tempTable = (Timetable*)malloc(sizeof(Timetable));

	tempTable->Size = 0;
	tempTable->_Head = 0;
	tempTable->_Tail = 0;

	for (int i = 0; i < BUF_Size; i++)
	{
		tempTable->_Buf[i] = NULL;
	}
	return tempTable;
}

void enqueue(Timetable* pThis, Class input)
{
	//Class를 할당받고 할당받은 Class 값 초기화
	Class* tempClass = (Class*)malloc(sizeof(Class));

	tempClass->Name = (char*)malloc(sizeof(char) * strlen(input.Name) + 1);
	strcpy(tempClass->Name, input.Name);
	
	tempClass->ZoomAdd = (char*)malloc(sizeof(char) * strlen(input.ZoomAdd) + 1);
	strcpy(tempClass->ZoomAdd, input.ZoomAdd);

	tempClass->StartTime = input.StartTime;

	pThis->_Buf[pThis->_Tail] = tempClass;
	pThis->_Tail++;
	pThis->Size++;
}


Class* look_head(Timetable* pThis)
{
	return pThis->_Buf[pThis->_Head];
}


void cut_head(Timetable* pThis)
{
	free(pThis->_Buf[pThis->_Head]->Name);
	free(pThis->_Buf[pThis->_Head]->ZoomAdd);
	free(pThis->_Buf[pThis->_Head]);
	pThis->_Buf[pThis->_Head] = NULL;
	pThis->Size--;
	pThis->_Head++;
}

Class* get_node_by_index(Timetable* pThis, int index)
{
	return pThis->_Buf[pThis->_Head + index];
}

//input1이 input2보다 작으면 데이터를 스왑
static void swap_number_by_size(int* input1, int* input2)
{
	int tmp;
	tmp = *input1;
	if (*input1 > *input2)
	{
		*input1 = *input2;
		*input2 = tmp;
	}
}

static void swap_start_time(Class* input1, Class* input2)
{
	DateTime temp;
	temp = input1->StartTime;
	input1->StartTime = input2->StartTime;
	input2->StartTime = temp;
}

bool swap_time_table(Timetable* pThis, int index1, int index2)
{

	int target1 = index1;
	int target2 = index2;

	swap_number_by_size(&target1, &target2);

	if (target1 < 0 || target2 > pThis->Size - 1)
	{
		return false;
	}

	target1 = target1 + pThis->_Head;
	target2 = target2 + pThis->_Head;

	Class* tmp = pThis->_Buf[target1];

	pThis->_Buf[target1] = pThis->_Buf[target2];
	pThis->_Buf[target2] = tmp;

	swap_start_time(pThis->_Buf[target1], pThis->_Buf[target2]);

	return true;
}

bool change_time_table(Timetable* pThis, Class input, int index)
{
	if (index > pThis->Size - 1)
	{
		return false;
	}

	Class* Target = get_node_by_index(pThis, index);

	//copy data in input to target. IF CLASS STRUCT ARE CHANGED, EDIT THIS
	free(Target->Name);
	free(Target->ZoomAdd);

	Target->Name = malloc(sizeof(char) * strlen(input.Name) + 1);
	strcpy(Target->Name, input.Name);

	Target->ZoomAdd = malloc(sizeof(char) * strlen(input.ZoomAdd) + 1);
	strcpy(Target->ZoomAdd, input.ZoomAdd);

	Target->StartTime = input.StartTime;

	return true;
}