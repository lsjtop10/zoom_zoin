#include "timetable.h"
#define _CRT_SECURE_NO_WARNINGS 

#define TEST1 0


#if TEST1
#include<stdio.h>
void showList(TimeTable* pThis)
{
	for (int i = 0; i < pThis->size; i++)
	{
		printf(getNodeByIndex(pThis, i)->name);
		printf(" ");
	}
}
#endif

TimeTable* initializeTimeTable()
{
	TimeTable* temptable = (TimeTable*)malloc(sizeof(TimeTable));
	temptable->_Head = temptable->_Tail = NULL;
	temptable->size = 0;
	return temptable;
}

void enqueue(TimeTable* pThis, Class input)
{
	//Class�� �Ҵ�ް� �Է¹��� input�� �°� �ʱ�ȭ
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

	pThis->_Tail->_next = NULL;
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

	if (index < 0 || index > pThis->size - 1)
	{
		return NULL;
	}

	for (int i = 0; i < index; i++)
	{
		horse = horse->_next;
	}

	return horse;
}

//input1�� input2���� ������ �����͸� ����
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
	changeNumberBySize(&target1, &target2);

	if (index1 == index2) return true;
	if (index1 < 0 || index2 > pThis->size - 1) return false;

	Class* c1p, * c1, * c1n;
	Class* c2p, * c2, * c2n;

	//���� ���� Head�� ����Ű�� ������ ���, �Է°��� head�� ���� �� ���
	Class temp = { "NULL","NULL",pThis->_Head->startTime, NULL };

	//�ٲ� ���� �ֺ��� ���Ҹ� ��������
	c1p = getNodeByIndex(pThis, target1 - 1);
	c2p = getNodeByIndex(pThis, target2 - 1);

	if (c1p == NULL)
	{

		temp._next = pThis->_Head;
		c1p = &temp;
	}


	c1 = c1p->_next;
	c2 = c2p->_next;

	c1n = c1->_next;
	c2n = c2->_next;

	//Todo: �ٲ� �� ��带 ��ũ�� ����Ʈ���� ����

	if (target1 + 1 == target2)
	{
		c1p->_next = c2n;
	}
	else
	{
		c1p->_next = c1n;
		c2p->_next = c2n;
	}

	//Todo: �ٲ� ������ ���� ��ũ�� ����Ʈ�� �ٽ� ����

	if (target1 + 1 == target2)
	{
		c1->_next = c1p->_next;
		c1p->_next = c2;
		c2->_next = c1;
	}
	else
	{
		c2->_next = c1p->_next;
		c1p->_next = c2;

		c1->_next = c2p->_next;
		c2p->_next = c1;

	}

	if (temp._next != NULL)
	{
		pThis->_Head = temp._next;
	}
	if (c2n == NULL)
	{
		pThis->_Tail = c1;
	}

	swapStartTime(c1, c2);

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
	Target->name = input.name;
	Target->zoomAdd = input.zoomAdd;
	Target->startTime = input.startTime;

	return true;
}