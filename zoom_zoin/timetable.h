#define _CRT_SECURE_NO_WARNINGS 
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

typedef struct tm DateTime;
typedef struct Class
{
	char* name;
	char* zoomAdd;
	DateTime startTime;
}Class;

typedef struct TimeTable
{
	int size;

	int _head;
	int _tail;

	Class* _Buf[10];
}TimeTable;

TimeTable* initializeTimeTable();
void enqueue(TimeTable* pThis, Class input);
Class* lookHead(TimeTable* pThis);
void cutHead(TimeTable* pThis);
Class* getNodeByIndex(TimeTable* pThis, int index);
bool swapTimeTable(TimeTable* pThis, int index1, int index2);
bool changeTimeTable(TimeTable* pThis, Class input, int index);
