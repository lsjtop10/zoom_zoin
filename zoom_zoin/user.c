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
	printf("<�ð�ǥ>\n");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("��°: "); printf(getNodeByIndex(ptimeTable, i - 1)->name);
		printf("\n");
	}

}

void showSettings()
{
	printf("<���� ����>\n");
	printf("���� ���� ���α׷�: "); printf(getProgramByIndex(getSettings()->UsedProgram)); printf("\n");
	printf("���� ���ð�: "); printf("%d", getSettings()->WaitMin); printf("  ��\n");
}

void showInitMenu(TimeTable* ptimeTable)
{
	while (true)
	{
		showTimetable(ptimeTable);
		showSettings();

		printf("1. �ð�ǥ ����\n");
		printf("2. ���� ����\n");
		printf("e: ������\n");
		printf("���Ͻô� ��ɿ� �ش��ϴ� ���ڳ� ���ĺ� �����ϼ���. \n");

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
			printf("�ùٸ� ���� �ƴմϴ�. �ٽ� �Է����ּ���.\n");
			system("cls");
			break;
		}
	}
}

static void onChangeTimeTableRequest(TimeTable* ptimeTable)
{
	printf("���Ͻô� ����� �������ּ���. \n");
	printf("1. n���ÿ� m������ ������ �ٲٱ�\n");
	printf("2. n���ø� ���ο� �������� �ٲٱ�\n");


	char inputb = '.';
	scanf("%c", &inputb);
	clearLineFromReadBuffer();
	switch (inputb)
	{
		int n, m;
	case '1':
		n = 0; m = 0;
		printf("n���ô� �����Դϱ�?\n");

		scanf("%d", &n);
		clearLineFromReadBuffer();

		printf("m���ô� �����Դϱ�?\n");

		scanf("%d", &m);
		clearLineFromReadBuffer();

		if (swapTimeTable(ptimeTable, n - 1, m - 1) == true)
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
		clearLineFromReadBuffer();
		Class temp;
		char sub[500];
		char addr[2048];

		printf("�ٲ� �ð�ǥ�� ������� �Է����ּ���. \n");
		scanf("%s", sub);
		clearLineFromReadBuffer();

		printf("�ٲ� �ð�ǥ�� �� ���� �ּҸ� �����ؼ� �Է����ּ���. \n");
		scanf("%s", addr);
		clearLineFromReadBuffer();

		temp.name = sub;
		temp.zoomAdd = addr;

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �ð� ������ �Է����ּ���. \n");
		scanf("%d", &temp.startTime.tm_hour);
		clearLineFromReadBuffer();

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �� ������ �Է����ּ���. \n");

		scanf("%d", &temp.startTime.tm_min);
		clearLineFromReadBuffer();

		changeTimeTable(ptimeTable, temp, n);
	default:
		break;
	}
}

static void onChanegeSettingRequest()
{

	printf("�̸� �����ؼ� ��ٸ� �ð��� �Է����ּ���.\n");
	scanf("%d", &getSettings()->WaitMin);
	clearLineFromReadBuffer();

	printf("<���α׷� ���>\n");
	for (int i = 0; i < Num_Of_Prog; i++)
	{
		printf("%d: ", i + 1); printf(getProgramByIndex(i));
		printf("\n");
	}
	printf("����� ���α׷��� ��ȣ�� �������ּ���. \n");
	int input;
	scanf("%d", &input);

	if (input < 0 || input > Num_Of_Prog)
	{
		printf("�߸��� �Է��Դϴ�. 1���� %d������ ���ڸ� �Է����ּ���. \n", Num_Of_Prog);
	}
	clearLineFromReadBuffer();

	getSettings()->UsedProgram = input - 1;
}