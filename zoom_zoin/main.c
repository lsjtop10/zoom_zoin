#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <windows.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"
#include <time.h>

TimeTable* timeTable;

void initalizeProgram()
{
	timeTable = initializeTimeTable();

	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	//Setting Load
	getSettings()->UsedProgram = Load_Setting(0);
	getSettings()->wait_min = Load_Setting(1);

	time_t t = time(NULL);
	struct tm times = *localtime(&t);


	for (int i = 0; i < 7; i++)
	{
		/*const char* key = NULL;
		key = Load_Subject_Obbject(i);
		*/
		const char* str = NULL;
		const char* timeTabled = strtok_s(Load_Timetable(i), ":", &str);

		const char* week = NULL;
		week = Load_timetable_week(times.tm_wday, i);
		//printf("%d. %s\n", i, week);

		DateTime tm;
		tm.tm_hour = atoi(timeTabled);
		tm.tm_min = atoi(str);

		const char* zoomAd = NULL;
		zoomAd = Load_Subject(week);
		
		Class class;
		class.name = week;
		class.zoomAdd = zoomAd;
		class.startTime = tm;

		//printf("%d, %s, %s, %s/%s(%d:%d)\n", i, week, zoomAd, timeTabled, str, tm.tm_hour, tm.tm_min);
		enqueue(timeTable, class);
	}

}

void joinZoom(Class *target)
{

	//실행 스크립트를 저장하는 데 필요한 메모리를 동적 할당
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
		//여기에 loop 처리

		//head불러오기
		Class* head = lookHead(timeTable);
		//현재 시간 불러오기
		time_t timer;
		DateTime *current;
		timer = time(NULL); // 현재 시각을 초 단위로 얻기

		current = localtime(&timer); 
		//만약 현재 시간이 줌 시작시간 분단위 - 사전 대기시간이면
		if (compareTime(subtractTime(head->startTime, convertMintoDT(getSettings()->WaitMin)), *current) == 1)
		{
			joinZoom(head);
			cutHead(timeTable);
		}
		
		Sleep(2000);
		
	}
}