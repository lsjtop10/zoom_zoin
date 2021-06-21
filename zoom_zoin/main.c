#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"
#include <time.h>

TimeTable* timeTable;

void initalizeProgram()
{
	timeTable = initializeTimeTable();

	//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	//Setting Load
	getSettings()->UsedProgram = Load_Setting(0);
	getSettings()->wait_min = Load_Setting(1);

	time_t t = time(NULL);
	struct tm times = *localtime(&t);


	for (int i = 0; i < 7; i++)
	{
		/*const char* key = NULL;
		key = Load_Subject_Obbject(i);
		*/
		const char* str = NULL;
		const char* timeTabled = strtok_s(Load_Timetable(i), ":", &str);

		const char* week = NULL;
		week = Load_timetable_week(times.tm_wday, i);
		//printf("%d. %s\n", i, week);

		DateTime tm;
		tm.tm_hour = atoi(timeTabled);
		tm.tm_min = atoi(str);

		const char* zoomAd = NULL;
		zoomAd = Load_Subject(week);
		
		Class class;
		class.name = week;
		class.zoomAdd = zoomAd;
		class.startTime = tm;

		//printf("%d, %s, %s, %s/%s(%d:%d)\n", i, week, zoomAd, timeTabled, str, tm.tm_hour, tm.tm_min);
		enqueue(timeTable, class);
	}

}

void joinZoom(Class target)
{

	//실행 스크립트를 저장하는 데 필요한 메모리를 동적 할당
	char* cmd = (char*)malloc(sizeof(char) * (strlen("start ") + strlen(getProgramByIndex(getSettings()->UsedProgram)) + strlen(target.zoomAdd)) + 5);
	strcpy(cmd, "start ");
	strcat(cmd, getProgramByIndex(getSettings()->UsedProgram));
	strcat(cmd, " \"");
	strcat(cmd, target.zoomAdd);
	strcat(cmd, "\"");
	system(cmd);
}
	

int main()
{
	initalizeProgram();
}