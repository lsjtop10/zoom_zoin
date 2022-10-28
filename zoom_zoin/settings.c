#include "settings.h"
#define _CRT_SECURE_NO_WARNINGS 
Settings _Settings;
char* Programs[Num_Of_Prog] = {"msedge","chrome","whale"};

char* get_program_by_index(int index)
{
	return Programs[index];
}

Settings* get_settings()
{
	return &_Settings;
}