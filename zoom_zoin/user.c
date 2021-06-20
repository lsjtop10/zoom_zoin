#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include "timetable.h"
#include "settings.h"


Settings st;

char* __getprog(int a) { return "국어"; }
Settings* __getsetting() 
{
	return &st;
}

void onChangeTimeTableRequest(TimeTable* ptimeTable);
void onChanegeSettingRequest();

static void clearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}


void showTimetable(TimeTable* ptimeTable)
{
	printf("<시간표>\n");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("번째: "); printf(getNodeByIndex(ptimeTable, i - 1)->name); \
		printf("\n");
	}

}

void showInitMenu(TimeTable* ptimeTable)
{
	showTimetable(ptimeTable);
	
	printf("<현재 설정>\n"); 
	printf("현재 쓰는 프로그램: "); printf("N/A");

	while (true)
	{

		printf("\n");
		printf("1. 시간표 변경\n");
		printf("2. 설정 변경\n");
		printf("e: 나가기\n");
		printf("원하시는 기능에 해당하는 숫자나 알파벳 선택하세요 \n");

		char input = '.';
		scanf("%c", &input);
		clearLineFromReadBuffer();

		switch (input)
		{
		case '1':
			onChangeTimeTableRequest(ptimeTable);
			break;
		case '2':
			onChanegeSettingRequest();
			break;
		case 'e':
			return;
		default:
			printf("올바른 값이 아닙니다. 다시 입력해주세요");
			break;
		}
	}
}

static void onChangeTimeTableRequest(TimeTable* ptimeTable)
{
	printf("원하시는 기능을 선택해주세요 \n");
	printf("1. n교시와 m교시의 과목을 바꾸기\n");
	printf("2. n교시를 새로운 과목으로 바꾸기\n");


	char inputb = '.';
	scanf("%c", &inputb);
	clearLineFromReadBuffer();
	switch (inputb)
	{
		int n, m;
	case '1':
		n = 0; m = 0;
		printf("n교시는 무엇입니까?\n");

		scanf("%d", &n);
		clearLineFromReadBuffer();

		printf("m교시는 무엇입니까?\n");

		scanf("%d", &m);
		clearLineFromReadBuffer();

		if (swapTimeTable(ptimeTable, n, m) == true)
		{
			printf("입력이 성공적으로 처리됐습니다. \n");
			swapTimeTable(ptimeTable, n - 1, m - 1);
			printf("바뀐 시간표: \n");
			showTimetable(ptimeTable);
		}
		else
		{
			printf("입력이 성공적으로 처리돼지 못했습니다. n과 m을 확인하고 다시 확인해주세요");
		}
		break;
	case '2':
		printf("n값을 입력해주세요");
		n = 0;

		scanf("%d", n);
		clearLineFromReadBuffer();
		Class temp = { "","" };
		char sub[500];
		char addr[2048];

		printf("바뀐 시간표의 과목명을 입력해주세요");
		scanf("%s", sub);
		clearLineFromReadBuffer();

		printf("바뀐 시간표의 줌 접속 주소를 복사해서 입력해주세요");
		scanf("%s", addr);
		clearLineFromReadBuffer();

		temp.name = sub;
		temp.zoomAdd = addr;

		printf("바뀐 시간표의 시작 시각의 시간 단위만 입력해주세요");
		scanf("%d", temp.startTime.tm_hour);
		clearLineFromReadBuffer();

		printf("바뀐 시간표의 시작 시각의 분 단위만 입력해주세요");

		scanf("%d", temp.startTime.tm_min);
		clearLineFromReadBuffer();

		changeTimeTable(ptimeTable, temp, n);
	default:
		break;
	}
}

static void onChanegeSettingRequest()
{
	Settings* st = __getsetting();

	printf("미리 접속해서 기다릴 시간을 입력해주세요.");
	scanf("%d", st->wait_min);

	//printf("사용할 프로그램의 번호를 선택해주세요.");
	//scanf("%d", addr);
}