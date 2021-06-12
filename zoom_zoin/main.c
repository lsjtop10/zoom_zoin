#include <stdlib.h>
#include "timetable.h"

#ifdef _DEBUG
void test()
{
	TimeTable* tt = initializeTimeTable();
	DateTime dt;
	dt.tm_hour = 1;
	dt.tm_min = 0;
	Class lic = { "0","https://zoom.us/문학",  dt};
	Class math = { "1","https://zoom.us/수학", dt};
	Class eng = { "2","https://zoom.us/eng",  dt};
	Class phy = { "3", "https://zoom.us/물리", dt };
	enqueue(tt, lic);
	enqueue(tt, math);
	enqueue(tt, eng);
	enqueue(tt, phy);

	getNodeByIndex(tt, 3);
}
#endif


int main()
{
	//test코드로 점프
#ifdef _DEBUG
	test();
#endif


}