#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#define BUF_Size 10

typedef struct tm DateTime;

typedef struct Class
{
	char* Name;
	char* ZoomAdd;
	DateTime StartTime;
}Class;

typedef struct TimeTable
{
	int Size;

	int _Head;
	int _Tail;

	Class* _Buf[BUF_Size];
}Timetable;

Timetable* initialize_timetable();
void enqueue(Timetable* pThis, Class input);
Class* look_head(Timetable* pThis);
void cut_head(Timetable* pThis);
Class* get_node_by_index(Timetable* pThis, int index);
bool swap_time_table(Timetable* pThis, int index1, int index2);
bool change_time_table(Timetable* pThis, Class input, int index);
