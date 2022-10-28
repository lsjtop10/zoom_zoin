#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <windows.h>
#include <stdlib.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"
#include <time.h>

Timetable* timeTable;

void initalize_program()
{
	timeTable = initialize_timetable();

	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	//Setting Load
	get_settings()->UsedProgram = load_setting(0);
	get_settings()->WaitMin = load_setting(1);

	time_t t = time(NULL);
	struct tm times = *localtime(&t);


	for (int i = 0; i < 7; i++)
	{
		const char* str = NULL;
		const char* timeTabled = strtok_s(load_timetable(i), ":", &str);

		const char* week = NULL;
		week = load_timetable_week(times.tm_wday, i);

		DateTime tm;
		tm.tm_hour = atoi(timeTabled);
		tm.tm_min = atoi(str);

		const char* zoomAd = NULL;
		zoomAd = load_subject(week);
		
		Class class;
		class.Name = week;
		class.ZoomAdd = zoomAd;
		class.StartTime = tm;

		enqueue(timeTable, class);
	}

}

void join_zoom(Class *target)
{

	//실행 스크립트를 저장하는 데 필요한 메모리를 동적 할당
	char* cmd = (char*)malloc(sizeof(char) * (strlen("start ") + strlen(get_program_by_index(get_settings()->UsedProgram)) + strlen(target->ZoomAdd)) + 5);
	strcpy(cmd, "start ");
	strcat(cmd, get_program_by_index(get_settings()->UsedProgram));
	strcat(cmd, " \"");
	strcat(cmd, target->ZoomAdd);
	strcat(cmd, "\"");
	system(cmd);
}

int convert_DT_to_MIN(DateTime input)
{
	int min = 0;
	min += input.tm_hour * 60;
	min += input.tm_min;
	return min;
}

DateTime convert_MIN_to_DT(int input)
{
	DateTime dt;
	dt.tm_hour = input / 60;
	dt.tm_min = input % 60;
	return dt;
}


int compare_time(DateTime input0, DateTime input1)
{
	int min0 = convert_DT_to_MIN(input0);
	int min1 = convert_DT_to_MIN(input1);

	if (min0 >= min1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

DateTime subtract_time(DateTime input1, DateTime input2)
{
	int min1 = convert_DT_to_MIN(input1);
	int min2 = convert_DT_to_MIN(input2);

	min2 = min1 - min2;

	return convert_MIN_to_DT(min2);
}

int main()
{
	initalize_program();
	show_Init_menu(timeTable);
	printf("지금부터 작동 시작합니다.\n");
	int period = 1;

	while (true)
	{
		//여기에 loop 처리

		//head불러오기
		Class* head = look_head(timeTable);
		
		if (head == NULL || head->Name == "null")
		{
			return 0;
		}

		//현재 시간 불러오기
		time_t timer;
		DateTime *current;
		timer = time(NULL); // 현재 시각을 초 단위로 얻기

		current = localtime(&timer); 

		//만약 현재 시간이 줌 시작시간 분단위 - 사전 대기시간이면
		if (compare_time(subtract_time(head->StartTime, convert_MIN_to_DT(get_settings()->WaitMin)), *current) == 1)
		{
			//system("tskkill /im zoom.exe");
			printf("%d교시 %s수업이 시작됐습니다 \n", period, head->Name);
			join_zoom(head);
			cut_head(timeTable);
			period++;
		}
		
		Sleep(2000);
		
	}
}