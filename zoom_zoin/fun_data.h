#pragma once
#include <stdio.h>
#include "parson.h"

int loadSetting(int type);
int loadTimetable(int ToDay);
const char* loadSubject(int type);
const char* loadSubjectObbject(int i);