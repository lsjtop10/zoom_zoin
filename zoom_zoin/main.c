#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include "settings.h"
#include "fun_data.h"
#include "timetable.h"
#include "user.h"


TimeTable* timeTable;
Settings setting;

void LoadTimeTableFromFile();
void initlizeProgram(); //�ʹ� �۾�

void joinZoom(Class target)
{
	//���� ��ũ��Ʈ�� �����ϴ� �� �ʿ��� �޸𸮸� ���� �Ҵ�
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

}