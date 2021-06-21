#pragma once
#include <stdio.h>
#include "parson.h"

int Load_Setting(int type);
const char* Load_Timetable(int ToDay);
const char* Load_Subject(const char* subject_name);
const char* Load_Subject_Obbject(int i);
const char* Load_timetable_week(int i, int num);