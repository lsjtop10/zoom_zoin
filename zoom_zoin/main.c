#include <stdlib.h>
#include "timetable.h"


#ifdef _DEBUG
void test()
{
	TimeTable* tt = initializeTimeTable();
	DateTime dt;
	dt.tm_hour = 1;
	dt.tm_min = 0;
	Class lic = { "0","",  dt};
	Class math = { "1","", dt};
	Class eng = { "2","",  dt};
	Class phy = { "3", "", dt};
	Class lic1 = { "4","",  dt };
	Class math2 = { "5","", dt };
	Class eng3 = { "6","",  dt };
	Class phy4 = { "7", "", dt };
	enqueue(tt, lic);
	enqueue(tt, math);
	enqueue(tt, eng);
	enqueue(tt, phy);
	enqueue(tt, lic1);
	enqueue(tt, math2);
	enqueue(tt, eng3);
	enqueue(tt, phy4);

	getNodeByIndex(tt, 3);

	swapTimeTable(tt, 0, 3);
	swapTimeTable(tt, 0, 3);

	swapTimeTable(tt, 4, 7);
	swapTimeTable(tt, 4, 7);

	swapTimeTable(tt, 2, 3);
	swapTimeTable(tt, 2, 3);

	swapTimeTable(tt, 4, 5);
	swapTimeTable(tt, 4, 5);
}

#endif


int main()
{
	//test코드로 점프
#ifdef _DEBUG
	test();
#endif


}