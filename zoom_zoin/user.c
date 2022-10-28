#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include "timetable.h"
#include "settings.h"

void on_change_timetable_request(Timetable* ptimeTable);
void on_chanege_setting_request();

static void clear_line_from_read_buffer(void)
{
	while (getchar() != '\n');
}


void show_timetable(Timetable* ptimeTable)
{
	printf("<시간표>\n");
	for (int i = 1; i <= ptimeTable->Size; i++)
	{
		printf("%d", i); printf("번째: "); printf(get_node_by_index(ptimeTable, i - 1)->Name);
		printf("\n");
	}

}

void show_settings()
{
	printf("<현재 설정>\n");
	printf("현재 쓰는 프로그램: "); printf(get_program_by_index(get_settings()->UsedProgram)); printf("\n");
	printf("사전 대기시간: "); printf("%d", get_settings()->WaitMin); printf("  분\n");
}

void show_Init_menu(Timetable* ptimeTable)
{
	while (true)
	{
		show_timetable(ptimeTable);
		show_settings();

		printf("1. 시간표 변경\n");
		printf("2. 설정 변경\n");
		printf("e: 나가기\n");
		printf("원하시는 기능에 해당하는 숫자나 알파벳 선택하세요. \n");

		char input = '.';
		scanf("%c", &input);
		clear_line_from_read_buffer();

		switch (input)
		{
		case '1':
			on_change_timetable_request(ptimeTable);
			system("cls");
			break;
		case '2':
			on_chanege_setting_request();
			system("cls");
			break;
		case 'e':
			return;
		case 't':
			cut_head(ptimeTable);
			show_timetable(ptimeTable);
			break;
		default:
			printf("올바른 값이 아닙니다. 다시 입력해주세요.\n");
			system("cls");
			break;
		}
	}
}

static void on_change_timetable_request(Timetable* ptimeTable)
{
	printf("원하시는 기능을 선택해주세요. \n");
	printf("1. n교시와 m교시의 과목을 바꾸기\n");
	printf("2. n교시를 새로운 과목으로 바꾸기\n");


	char inputb = '.';
	scanf("%c", &inputb);
	clear_line_from_read_buffer();
	switch (inputb)
	{
		int n, m;
	case '1':
		n = 0; m = 0;
		printf("n교시는 무엇입니까?\n");

		scanf("%d", &n);
		clear_line_from_read_buffer();

		printf("m교시는 무엇입니까?\n");

		scanf("%d", &m);
		clear_line_from_read_buffer();

		if (swap_time_table(ptimeTable, n - 1, m - 1) == true)
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
		clear_line_from_read_buffer();
		Class temp;
		char sub[500];
		char addr[2048];

		printf("바뀐 시간표의 과목명을 입력해주세요. \n");
		scanf("%s", sub);
		clear_line_from_read_buffer();

		printf("바뀐 시간표의 줌 접속 주소를 복사해서 입력해주세요. \n");
		scanf("%s", addr);
		clear_line_from_read_buffer();

		temp.Name = sub;
		temp.ZoomAdd = addr;

		printf("바뀐 시간표의 시작 시각의 시간 단위만 입력해주세요. \n");
		scanf("%d", &temp.StartTime.tm_hour);
		clear_line_from_read_buffer();

		printf("바뀐 시간표의 시작 시각의 분 단위만 입력해주세요. \n");

		scanf("%d", &temp.StartTime.tm_min);
		clear_line_from_read_buffer();

		change_time_table(ptimeTable, temp, n);
	default:
		break;
	}
}

static void on_chanege_setting_request()
{

	printf("미리 접속해서 기다릴 시간을 입력해주세요.\n");
	scanf("%d", &get_settings()->WaitMin);
	clear_line_from_read_buffer();

	printf("<프로그램 목록>\n");
	for (int i = 0; i < Num_Of_Prog; i++)
	{
		printf("%d: ", i + 1); printf(get_program_by_index(i));
		printf("\n");
	}
	printf("사용할 프로그램의 번호를 선택해주세요. \n");
	int input;
	scanf("%d", &input);

	if (input < 0 || input > Num_Of_Prog)
	{
		printf("잘못된 입력입니다. 1에서 %d까지의 숫자를 입력해주세요. \n", Num_Of_Prog);
	}
	clear_line_from_read_buffer();

	get_settings()->UsedProgram = input - 1;
}