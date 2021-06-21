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

	//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����

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