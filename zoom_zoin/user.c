#include <stdlib.h>
#include "timetable.h"
#include "settings.h"

char* __getprog(int a) { return "국어"; }
Settings* __getsetting() 
{
	Settings settings;
	return &settings;
}

void OnChangeTimeTableRequest(TimeTable* ptimeTable);
static void OnChanegeSettingRequest();

static void ShowTimetable(TimeTable* ptimeTable)
{
	printf("시간표:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("교시:"); printf(getNodeByIndex(ptimeTable, i - 1)->name);
	}

}

void shwoInitMenu(TimeTable* ptimeTable)
{
	printf("시간표:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("교시:"); printf(getNodeByIndex(ptimeTable , i - 1 )->name);
	}
	
	printf("<현재 설정>\n"); 
	printf("현재 쓰는 프로그램: "); printf()

	while (true)
	{
		char input = '.';
		printf("원하시는 기능에 해당하는 숫자나 알파벳 선택하세요 \n");

		scanf("%c", &input);
		printf("1. 시간표 변경");
		printf("2. 설정 변경");
		printf("e: 나가기");

		switch (input)
		{
		case '1':
			OnChangeTimeTableRequest(ptimeTable);
			break;
		case '2':
			OnChangeSettingRequest();
			break;
		case 'e':
			return;
		default:
			printf("올바른 값이 아닙니다. 다시 입력해주세요");
			break;
		}
	}
}

static void OnChangeTimeTableRequest(TimeTable* ptimeTable)
{

}

static void OnChanegeSettingRequest()
{

}