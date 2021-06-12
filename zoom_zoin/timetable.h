#define _CRT_SECURE_NO_WARNINGS 
#include <time.h>
#include <stdlib.h>

typedef struct tm DateTime;
typedef struct Class
{
	char* name;
	char* zoomAdd;
	DateTime startTime;
	struct Class* next;
}Class;

typedef struct TimeTable
{
	Class* Head;
	Class* Tail;
	int size;
}TimeTable;

TimeTable* initializeTimeTable();
void enqueue(TimeTable* pThis, Class input);
Class* lookHead(TimeTable* pThis);
void cutHead(TimeTable* pThis);
Class* getNodeByIndex(TimeTable* pThis, int index);
