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
	printf("<�ð�ǥ>\n");
	for (int i = 1; i <= ptimeTable->Size; i++)
	{
		printf("%d", i); printf("��°: "); printf(get_node_by_index(ptimeTable, i - 1)->Name);
		printf("\n");
	}

}

void show_settings()
{
	printf("<���� ����>\n");
	printf("���� ���� ���α׷�: "); printf(get_program_by_index(get_settings()->UsedProgram)); printf("\n");
	printf("���� ���ð�: "); printf("%d", get_settings()->WaitMin); printf("  ��\n");
}

void show_Init_menu(Timetable* ptimeTable)
{
	while (true)
	{
		show_timetable(ptimeTable);
		show_settings();

		printf("1. �ð�ǥ ����\n");
		printf("2. ���� ����\n");
		printf("e: ������\n");
		printf("���Ͻô� ��ɿ� �ش��ϴ� ���ڳ� ���ĺ� �����ϼ���. \n");

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
			printf("�ùٸ� ���� �ƴմϴ�. �ٽ� �Է����ּ���.\n");
			system("cls");
			break;
		}
	}
}

static void on_change_timetable_request(Timetable* ptimeTable)
{
	printf("���Ͻô� ����� �������ּ���. \n");
	printf("1. n���ÿ� m������ ������ �ٲٱ�\n");
	printf("2. n���ø� ���ο� �������� �ٲٱ�\n");


	char inputb = '.';
	scanf("%c", &inputb);
	clear_line_from_read_buffer();
	switch (inputb)
	{
		int n, m;
	case '1':
		n = 0; m = 0;
		printf("n���ô� �����Դϱ�?\n");

		scanf("%d", &n);
		clear_line_from_read_buffer();

		printf("m���ô� �����Դϱ�?\n");

		scanf("%d", &m);
		clear_line_from_read_buffer();

		if (swap_time_table(ptimeTable, n - 1, m - 1) == true)
		{
			printf("�Է��� ���������� ó���ƽ��ϴ�. \n");
		}
		else
		{
			printf("�Է��� ���������� ó������ ���߽��ϴ�. n�� m�� Ȯ���ϰ� �ٽ� Ȯ�����ּ���. \n");
		}
		break;
	case '2':
		printf("n���� �Է����ּ���. \n");
		n = 0;

		scanf("%d", &n);
		clear_line_from_read_buffer();
		Class temp;
		char sub[500];
		char addr[2048];

		printf("�ٲ� �ð�ǥ�� ������� �Է����ּ���. \n");
		scanf("%s", sub);
		clear_line_from_read_buffer();

		printf("�ٲ� �ð�ǥ�� �� ���� �ּҸ� �����ؼ� �Է����ּ���. \n");
		scanf("%s", addr);
		clear_line_from_read_buffer();

		temp.Name = sub;
		temp.ZoomAdd = addr;

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �ð� ������ �Է����ּ���. \n");
		scanf("%d", &temp.StartTime.tm_hour);
		clear_line_from_read_buffer();

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �� ������ �Է����ּ���. \n");

		scanf("%d", &temp.StartTime.tm_min);
		clear_line_from_read_buffer();

		change_time_table(ptimeTable, temp, n);
	default:
		break;
	}
}

static void on_chanege_setting_request()
{

	printf("�̸� �����ؼ� ��ٸ� �ð��� �Է����ּ���.\n");
	scanf("%d", &get_settings()->WaitMin);
	clear_line_from_read_buffer();

	printf("<���α׷� ���>\n");
	for (int i = 0; i < Num_Of_Prog; i++)
	{
		printf("%d: ", i + 1); printf(get_program_by_index(i));
		printf("\n");
	}
	printf("����� ���α׷��� ��ȣ�� �������ּ���. \n");
	int input;
	scanf("%d", &input);

	if (input < 0 || input > Num_Of_Prog)
	{
		printf("�߸��� �Է��Դϴ�. 1���� %d������ ���ڸ� �Է����ּ���. \n", Num_Of_Prog);
	}
	clear_line_from_read_buffer();

	get_settings()->UsedProgram = input - 1;
}