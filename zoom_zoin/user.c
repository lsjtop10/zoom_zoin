#include <stdlib.h>
#include "timetable.h"
#include "settings.h"

char* __getprog(int a) { return "����"; }
Settings* __getsetting() 
{
	Settings settings;
	return &settings;
}

void OnChangeTimeTableRequest(TimeTable* ptimeTable);
static void OnChanegeSettingRequest();

static void ShowTimetable(TimeTable* ptimeTable)
{
	printf("�ð�ǥ:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("����:"); printf(getNodeByIndex(ptimeTable, i - 1)->name);
	}

}

void shwoInitMenu(TimeTable* ptimeTable)
{
	printf("�ð�ǥ:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("����:"); printf(getNodeByIndex(ptimeTable , i - 1 )->name);
	}
	
	printf("<���� ����>\n"); 
	printf("���� ���� ���α׷�: "); printf()

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
			OnChangeSettingRequest();
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

}

static void OnChanegeSettingRequest()
{

}