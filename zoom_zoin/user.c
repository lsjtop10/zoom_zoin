#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include "timetable.h"
#include "settings.h"

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
		printf("%d", i); printf("번째: "); printf(getNodeByIndex(ptimeTable, i - 1)->name);
		printf("\n");
	}

}

void showSettings()
{
	printf("<현재 설정>\n");
	printf("현재 쓰는 프로그램: "); printf(getProgramByIndex(getSettings()->UsedProgram)); printf("\n");
	printf("사전 대기시간: "); printf("%d", getSettings()->WaitMin); printf("  분\n");
}

void showInitMenu(TimeTable* ptimeTable)
{
	while (true)
	{
		showTimetable(ptimeTable);
		showSettings();

		printf("1. 시간표 변경\n");
		printf("2. 설정 변경\n");
		printf("e: 나가기\n");
		printf("원하시는 기능에 해당하는 숫자나 알파벳 선택하세요. \n");

		char input = '.';
		scanf("%c", &input);
		clearLineFromReadBuffer();

		switch (input)
		{
		case '1':
			onChangeTimeTableRequest(ptimeTable);
			system("cls");
			break;
		case '2':
			onChanegeSettingRequest();
			system("cls");
			break;
		case 'e':
			return;
		case 't':
			cutHead(ptimeTable);
			showTimetable(ptimeTable);
			break;
		default:
			printf("올바른 값이 아닙니다. 다시 입력해주세요.\n");
			system("cls");
			break;
		}
	}
}

static void onChangeTimeTableRequest(TimeTable* ptimeTable)
{
	printf("원하시는 기능을 선택해주세요. \n");
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

		if (swapTimeTable(ptimeTable, n - 1, m - 1) == true)
		{
			printf("입력이 성공적으로 처리됐습니다. \n");
		}
		else
		{
			printf("입력을 성공적으로 처리하지 못했습니다. n과 m을 확인하고 다시 확인해주세요. \n");
		}
		break;
	case '2':
		printf("n값을 입력해주세요. \n");
		n = 0;

		scanf("%d", &n);
		clearLineFromReadBuffer();
		Class temp;
		char sub[500];
		char addr[2048];

		printf("바뀐 시간표의 과목명을 입력해주세요. \n");
		scanf("%s", sub);
		clearLineFromReadBuffer();

		printf("바뀐 시간표의 줌 접속 주소를 복사해서 입력해주세요. \n");
		scanf("%s", addr);
		clearLineFromReadBuffer();

		temp.name = sub;
		temp.zoomAdd = addr;

		printf("바뀐 시간표의 시작 시각의 시간 단위만 입력해주세요. \n");
		scanf("%d", &temp.startTime.tm_hour);
		clearLineFromReadBuffer();

		printf("바뀐 시간표의 시작 시각의 분 단위만 입력해주세요. \n");

		scanf("%d", &temp.startTime.tm_min);
		clearLineFromReadBuffer();

		changeTimeTable(ptimeTable, temp, n);
	default:
		break;
	}
}

static void onChanegeSettingRequest()
{

	printf("미리 접속해서 기다릴 시간을 입력해주세요.\n");
	scanf("%d", &getSettings()->WaitMin);
	clearLineFromReadBuffer();

	printf("<프로그램 목록>\n");
	for (int i = 0; i < Num_Of_Prog; i++)
	{
		printf("%d: ", i + 1); printf(getProgramByIndex(i));
		printf("\n");
	}
	printf("사용할 프로그램의 번호를 선택해주세요. \n");
	int input;
	scanf("%d", &input);

	if (input < 0 || input > Num_Of_Prog)
	{
		printf("잘못된 입력입니다. 1에서 %d까지의 숫자를 입력해주세요. \n", Num_Of_Prog);
	}
	clearLineFromReadBuffer();

	getSettings()->UsedProgram = input - 1;
}