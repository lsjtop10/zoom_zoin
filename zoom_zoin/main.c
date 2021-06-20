#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"

 

TimeTable* timeTable;

void initalizeProgram()
{
	timeTable = initializeTimeTable();

	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

		//Setting Load
	getSettings()->UsedProgram = Load_Setting(0);
	getSettings()->wait_min = Load_Setting(1);

	for (int i = 0; i < 7; i++)
	{
		const char* key = NULL;
		key = Load_Subject_Obbject(i);

		DateTime DTime;
		DTime.tm_hour = 8;
		DTime.tm_min = 0;

		const char* zoomAd = NULL;
		zoomAd = Load_Subject(i);

		Class class;
		class.name = key;
		class.zoomAdd = zoomAd;
		class.startTime = DTime;

		printf("%d, %s, %s\n", i, key, zoomAd);
		enqueue(timeTable, class);
	}


	/*
	1. 파싱 -> class 구조체를 채운다
	2. 채운 구조체를 enqueue함수를 호출해서 timetable큐에 집어넣는다.
	 : 1. "문학", "httpls?dfdf", 9:00
		a b c d f
	   Class a;
	   a.name
	   a.zoomaddr
	   c.starttime
	   enqueue (timetable, class)
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
		pThis->_Tail->_next = NULL;
	}
	Load_subject("과학")
		-> 링크
	char* name;
	char* zoomAdd;
	DateTime startTime;
	subject
	{
		"과학": "www.zoom.com",
		"수학": "www.zoom.com"
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

void joinZoom(Class target)
{

	//실행 스크립트를 저장하는 데 필요한 메모리를 동적 할당
	char* cmd = (char*)malloc(sizeof(char) * (strlen("start ") + strlen(getProgramByIndex(getSettings()->UsedProgram)) + strlen(target.zoomAdd)) + 5);
	strcpy(cmd, "start ");
	strcat(cmd, getProgramByIndex(getSettings()->UsedProgram));
	strcat(cmd, " \"");
	strcat(cmd, target.zoomAdd);
	strcat(cmd, "\"");
	system(cmd);
}
	

int main()
{
	initalizeProgram();
	showInitMenu(timeTable);

	while (true)
	{
		//여기에 loop 처리
	}
}