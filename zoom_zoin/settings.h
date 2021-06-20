#pragma once

typedef struct Settings
{
	int UsedProgram;
	int wait_min;
	char* Programs[3];
} Settings;

char* getProgramsByIndex(int index);
