#include <stdlib.h>
#include "timetable.h"

int main()
{
	Class cls;
	DateTime dt;
	dt.tm_min = 3;
	cls.name = "±¹¾î";
	cls.zoomAdd = "http";
	cls.startTime = dt;

	TimeTable* tt = (TimeTable*)malloc(sizeof(TimeTable));
	initializeTimeTable(tt);
	enqueue(tt, cls);
	enqueue(tt, cls);
}