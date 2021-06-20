#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"


TimeTable* timeTable;
Settings setting;

void LoadTimeTableFromFile();
void initlizeProgram(); //초반 작업

void joinZoom(Class target)
{
	//실행 스크립트를 저장하는 데 필요한 메모리를 동적 할당
	char* cmd = (char*)malloc(sizeof(char) * ( strlen("start ") + strlen(getProgramByIndex(getSettings()->UsedProgram)) + strlen(target.zoomAdd)) + 5);
	strcpy(cmd, "start ");
	strcat(cmd, getProgramByIndex(getSettings()->UsedProgram));
	strcat(cmd, " \"");
	strcat(cmd, target.zoomAdd);
	strcat(cmd, "\"");
	system(cmd);
}

int main()
{
	Class test = { "문학", "https://us02web.zoom.us/j/6485437509?pwd=WE50VzZLUE4yUG1nMU4wRkh1SlBRUT09" };
	getSettings()->UsedProgram = 1;
	joinZoom(test);
}