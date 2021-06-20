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

	//Remark: Tail의 next노드는 항상 NULL
	struct Class* _next;
}Class;

typedef struct TimeTable
{
	int size;

	int _head;
	int _tail
}TimeTable;

TimeTable* initializeTimeTable();
void enqueue(TimeTable* pThis, Class input);
Class* lookHead(TimeTable* pThis);
void cutHead(TimeTable* pThis);
Class* getNodeByIndex(TimeTable* pThis, int index);
bool swapTimeTable(TimeTable* pThis, int index1, int index2);
bool changeTimeTable(TimeTable* pThis, Class input, int index);
