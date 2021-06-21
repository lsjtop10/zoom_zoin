#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <windows.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

 

TimeTable* timeTable;

void initalizeProgram()
{
	timeTable = initializeTimeTable();

	//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����

		//Setting Load
	getSettings()->UsedProgram = loadSetting(0);
	getSettings()->WaitMin = loadSetting(1);

	for (int i = 0; i < 7; i++)
	{
		const char* key = NULL;
		key = loadSubjectObbject(i);

		DateTime DTime;
		DTime.tm_hour = 8;
		DTime.tm_min = 0;

		const char* zoomAd = NULL;
		zoomAd = loadSubject(i);

		Class class;
		class.name = key;
		class.zoomAdd = zoomAd;
		class.startTime = DTime;

		enqueue(timeTable, class);
	}


	/*
	1. �Ľ� -> class ����ü�� ä���
	2. ä�� ����ü�� enqueue�Լ��� ȣ���ؼ� timetableť�� ����ִ´�.
	 : 1. "����", "httpls?dfdf", 9:00
		a b c d f
	   Class a;
	   a.name
	   a.zoomaddr
	   c.starttime
	   enqueue (timetable, class)
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
	Load_subject("����")
		-> ��ũ
	char* name;
	char* zoomAdd;
	DateTime startTime;
	subject
	{
		"����": "www.zoom.com",
		"����": "www.zoom.com"
	}
	timetable
	{
		"Class_1": 5,
		"Class_2": 23,
		"Class_3": 10,
		"Class_4": 20,
		"Class_5": 50,
		"Class_6": 50,
		"Class_7": 35
	}
	*/

}

void joinZoom(Class *target)
{

	//���� ��ũ��Ʈ�� �����ϴ� �� �ʿ��� �޸𸮸� ���� �Ҵ�
	char* cmd = (char*)malloc(sizeof(char) * (strlen("start ") + strlen(getProgramByIndex(getSettings()->UsedProgram)) + strlen(target->zoomAdd)) + 5);
	strcpy(cmd, "start ");
	strcat(cmd, getProgramByIndex(getSettings()->UsedProgram));
	strcat(cmd, " \"");
	strcat(cmd, target->zoomAdd);
	strcat(cmd, "\"");
	system(cmd);
}

int convertDTtoMin(DateTime input)
{
	int min = 0;
	min += input.tm_hour * 60;
	min += input.tm_min;
	return min;
}

DateTime convertMintoDT(int input)
{
	DateTime dt;
	dt.tm_hour = input / 60;
	dt.tm_min = input % 60;
	return dt;
}


int compareTime(DateTime input0, DateTime input1)
{
	int min0 = convertDTtoMin(input0);
	int min1 = convertDTtoMin(input1);

	if (min0 >= min1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//
DateTime subtractTime(DateTime input1, DateTime input2)
{
	int min1 = convertDTtoMin(input1);
	int min2 = convertDTtoMin(input2);

	min2 = min1 - min2;

	return convertMintoDT(min2);
}

int main()
{
	initalizeProgram();
	showInitMenu(timeTable);

	while (true)
	{
		//���⿡ loop ó��

		//head�ҷ�����
		Class* head = lookHead(timeTable);
		//���� �ð� �ҷ�����
		time_t timer;
		DateTime *current;
		timer = time(NULL); // ���� �ð��� �� ������ ���

		current = localtime(&timer); 
		//���� ���� �ð��� �� ���۽ð� �д��� - ���� ���ð��̸�
		if (compareTime(subtractTime(head->startTime, convertMintoDT(getSettings()->WaitMin)), *current) == 1)
		{
			joinZoom(head);
			cutHead(timeTable);
		}
		
		Sleep(2000);
		
	}
}