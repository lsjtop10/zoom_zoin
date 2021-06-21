#pragma once
#define Num_Of_Prog 3

typedef struct Settings
{
	int UsedProgram;
	int WaitMin;
} Settings;

char* getProgramByIndex(int index); 
Settings* getSettings();
