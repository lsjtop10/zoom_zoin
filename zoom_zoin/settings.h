#pragma once
#define Num_Of_Prog 3

typedef struct Settings
{
	int UsedProgram;
	int WaitMin;
} Settings;

char* get_program_by_index(int index); 
Settings* get_settings();
