#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include "timetable.h"
#include "settings.h"


Settings st;

char* __getprog(int a) { return "����"; }
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
	printf("<�ð�ǥ>\n");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("��°: "); printf(getNodeByIndex(ptimeTable, i - 1)->name); \
		printf("\n");
	}

}

void showInitMenu(TimeTable* ptimeTable)
{
	showTimetable(ptimeTable);
	
	printf("<���� ����>\n"); 
	printf("���� ���� ���α׷�: "); printf("N/A");

	while (true)
	{

		printf("\n");
		printf("1. �ð�ǥ ����\n");
		printf("2. ���� ����\n");
		printf("e: ������\n");
		printf("���Ͻô� ��ɿ� �ش��ϴ� ���ڳ� ���ĺ� �����ϼ��� \n");

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
			printf("�ùٸ� ���� �ƴմϴ�. �ٽ� �Է����ּ���");
			break;
		}
	}
}

static void onChangeTimeTableRequest(TimeTable* ptimeTable)
{
	printf("���Ͻô� ����� �������ּ��� \n");
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

		if (swapTimeTable(ptimeTable, n, m) == true)
		{
			printf("�Է��� ���������� ó���ƽ��ϴ�. \n");
			swapTimeTable(ptimeTable, n - 1, m - 1);
			printf("�ٲ� �ð�ǥ: \n");
			showTimetable(ptimeTable);
		}
		else
		{
			printf("�Է��� ���������� ó������ ���߽��ϴ�. n�� m�� Ȯ���ϰ� �ٽ� Ȯ�����ּ���");
		}
		break;
	case '2':
		printf("n���� �Է����ּ���");
		n = 0;

		scanf("%d", n);
		clearLineFromReadBuffer();
		Class temp = { "","" };
		char sub[500];
		char addr[2048];

		printf("�ٲ� �ð�ǥ�� ������� �Է����ּ���");
		scanf("%s", sub);
		clearLineFromReadBuffer();

		printf("�ٲ� �ð�ǥ�� �� ���� �ּҸ� �����ؼ� �Է����ּ���");
		scanf("%s", addr);
		clearLineFromReadBuffer();

		temp.name = sub;
		temp.zoomAdd = addr;

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �ð� ������ �Է����ּ���");
		scanf("%d", temp.startTime.tm_hour);
		clearLineFromReadBuffer();

		printf("�ٲ� �ð�ǥ�� ���� �ð��� �� ������ �Է����ּ���");

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

	printf("�̸� �����ؼ� ��ٸ� �ð��� �Է����ּ���.");
	scanf("%d", st->wait_min);

	//printf("����� ���α׷��� ��ȣ�� �������ּ���.");
	//scanf("%d", addr);
}