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

void OnChangeTimeTableRequest(TimeTable* ptimeTable);
void OnChanegeSettingRequest();

static void ShowTimetable(TimeTable* ptimeTable)
{
	printf("�ð�ǥ:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("����"); printf(getNodeByIndex(ptimeTable, i - 1)->name);
	}

}

void showInitMenu(TimeTable* ptimeTable)
{
	printf("�ð�ǥ:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("����:"); printf(getNodeByIndex(ptimeTable , i - 1 )->name);
	}
	
	printf("<���� ����>\n"); 
	printf("���� ���� ���α׷�: "); printf("N/A");

	while (true)
	{
		char input = '.';
		printf("���Ͻô� ��ɿ� �ش��ϴ� ���ڳ� ���ĺ� �����ϼ��� \n");

		scanf("%c", &input);
		printf("1. �ð�ǥ ����");
		printf("2. ���� ����");
		printf("e: ������");

		switch (input)
		{
		case '1':
			OnChangeTimeTableRequest(ptimeTable);
			break;
		case '2':
			OnChanegeSettingRequest();
			break;
		case 'e':
			return;
		default:
			printf("�ùٸ� ���� �ƴմϴ�. �ٽ� �Է����ּ���");
			break;
		}
	}
}

static void OnChangeTimeTableRequest(TimeTable* ptimeTable)
{
	printf("���Ͻô� ����� �������ּ��� \n");
	printf("1. n���ÿ� m������ ������ �ٲٱ�\n");
	printf("2. n���ø� ���ο� �������� �ٲٱ�\n");

	char input;
	scanf("%c", &input);

	switch (input)
	{
			int n, m;
		case '1':
			n = 0; m = 0;
			printf("n���ô� �����Դϱ�?\n");
			scanf("%d", &n);
			printf("m���ô� �����Դϱ�?\n");
			scanf("%d", &m);

			if (swapTimeTable(ptimeTable, n, m) == true)
			{
				printf("�Է��� ���������� ó���ƽ��ϴ�. \n");
				printf("�ٲ� �ð�ǥ: \n");
				ShowTimetable(ptimeTable);
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
			Class temp;
			printf("�ٲ� �ð�ǥ�� ������� �Է����ּ���");
			
			printf("�ٲ� �ð�ǥ�� �� ���� �ּҸ� �����ؼ� �Է����ּ���");

			printf("�ٲ� �ð�ǥ�� ���� �ð��� �ð� ������ �Է����ּ���");

			printf("�ٲ� �ð�ǥ�� ���� �ð��� �� ������ �Է����ּ���");

	default:
		break;
	}
}

static void OnChanegeSettingRequest()
{

}