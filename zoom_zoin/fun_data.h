#pragma once
#include <stdio.h>
#include "parson.h"

int load_setting(int type);
const char* load_timetable(int ToDay);
const char* load_subject(const char* subject_name);
const char* Load_Subject_Obbject(int i);
const char* load_timetable_week(int i, int num);