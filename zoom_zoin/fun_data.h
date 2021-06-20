#pragma once
#include <stdio.h>
#include "parson.h"

int Load_Setting(int type);
int Load_Timetable(int ToDay);
const char* Load_Subject(int type);
const char* Load_Subject_Obbject(int i);