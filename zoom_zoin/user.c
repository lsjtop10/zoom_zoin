#include <stdlib.h>
#include "timetable.h"
#include "settings.h"

void shwoInitMenu(TimeTable* ptimeTable, Settings* setting)
{
	printf("�ð�ǥ:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("����:"); printf(getNodeByIndex(ptimeTable , i - 1 )->name);
	}
	
	printf("<���� ����>\n"); 
	printf("���� ���� ���α׷�: "); printf();

	char input;
	printf("���Ͻô� ��ɿ� �ش��ϴ� ���ڳ� ���ĺ� �����ϼ��� \n");
	scanf("%c", &input);
	printf("1. �ð�ǥ ����");
	printf("2. ���� ����");
	printf("e: ������")
}

static void inputChangeTimeTable()
{

}