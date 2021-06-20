#include "settings.h"

Settings settings;
char* Programs[3] = {"msedge","chrome","whale"};

char* getProgramsByIndex(int index)
{
	return Programs[index];
}

Settings* getSettings()
{
	return &settings;
}