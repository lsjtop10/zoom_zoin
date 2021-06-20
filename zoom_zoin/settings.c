#include "settings.h"

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