#include "settings.h"
#include "fun_data.h"
#include "timetable.h"


TimeTable* timeTable;
Settings setting;

 //초반 작업

void initalizeProgram()
{
	timeTable = initializeTimeTable();

//todo: 여기다가 시간표 load해서 enqueue하는 부분 구현

	//Setting Load
	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);
	
	//시간표(과목/줌주소/시작시간) Load
	Class class;
	class.name = "문학";
	class.zoomAdd = "wwww.zoom.us";
	//class.startTime = 0;

	enqueue(timeTable, class);



	/* 
	
	1. 파싱 -> class 구조체를 채운다
	2. 채운 구조체를 enqueue함수를 호출해서 timetable큐에 집어넣는다.

	 : 1. "문학", "httpls?dfdf", 9:00
	

		a b c d f 

	   Class a;
	   a.name 
	   a.zoomaddr
	   c.starttime 
	   enqueue (timetable, class)

	void enqueue(TimeTable* pThis, Class input)
	{
		//Class를 할당받고 입력받은 input에 맞게 초기화
		Class* tempClass = (Class*)malloc(sizeof(Class));
		tempClass->name = input.name;
		tempClass->zoomAdd = input.zoomAdd;
		tempClass->startTime = input.startTime;

		if (pThis->size == 0)
		{
			pThis->_Head = tempClass;
			pThis->size++;
			pThis->_Tail = tempClass;
		}
		else
		{
			pThis->_Tail->_next = tempClass;
			pThis->_Tail = pThis->_Tail->_next;
			pThis->size++;
		}

		pThis->_Tail->_next = NULL;
	}


	
	Load_subject("과학")
		-> 링크

	char* name;
	char* zoomAdd;
	DateTime startTime;

	subject
    {
		"과학": "www.zoom.com",
		"수학": "www.zoom.com"
	}

	timetable
	{
		"Class_1": 5,
		"Class_2": 23,
		"Class_3": 10,
		"Class_4": 20,
		"Class_5": 50,
		"Class_6": 50,
		"Class_7": 35
	}

	*/
	
}

int main()
{
	initalizeProgram();

	/*shwoInitMenu();

	while (true)
	{

	}*/
}