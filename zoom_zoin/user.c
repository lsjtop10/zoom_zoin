#include <stdlib.h>
#include "timetable.h"
#include "settings.h"

void shwoInitMenu(TimeTable* ptimeTable, Settings* setting)
{
	printf("시간표:");
	for (int i = 1; i <= ptimeTable->size; i++)
	{
		printf("%d", i); printf("교시:"); printf(getNodeByIndex(ptimeTable , i - 1 )->name);
	}
	
	printf("<현재 설정>\n"); 
	printf("현재 쓰는 프로그램: "); printf();

	char input;
	printf("원하시는 기능에 해당하는 숫자나 알파벳 선택하세요 \n");
	scanf("%c", &input);
	printf("1. 시간표 변경");
	printf("2. 설정 변경");
	printf("e: 나가기")
}

static void inputChangeTimeTable()
{

}