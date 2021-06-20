#include "settings.h"
#define _CRT_SECURE_NO_WARNINGS 
Settings settings;
char* Programs[Num_Of_Prog] = {"msedge","chrome","whale"};

char* getProgramByIndex(int index)
{
	return Programs[index];
}

Settings* getSettings()
{
	return &settings;
}