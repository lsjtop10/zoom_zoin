#include "settings.h"
#include "fun_data.h"
#include "timetable.h"


TimeTable* timeTable;
Settings setting;

 //�ʹ� �۾�

void initalizeProgram()
{
	timeTable = initializeTimeTable();

//todo: ����ٰ� �ð�ǥ load�ؼ� enqueue�ϴ� �κ� ����

	//Setting Load
	setting.UsedProgram = Load_Setting(0);
	setting.wait_min = Load_Setting(1);
	
	//�ð�ǥ(����/���ּ�/���۽ð�) Load
	Class class;
	class.name = "����";
	class.zoomAdd = "wwww.zoom.us";
	//class.startTime = 0;

	enqueue(timeTable, class);



	/* 
	
	1. �Ľ� -> class ����ü�� ä���
	2. ä�� ����ü�� enqueue�Լ��� ȣ���ؼ� timetableť�� ����ִ´�.

	 : 1. "����", "httpls?dfdf", 9:00
	

		a b c d f 

	   Class a;
	   a.name 
	   a.zoomaddr
	   c.starttime 
	   enqueue (timetable, class)

	void enqueue(TimeTable* pThis, Class input)
	{
		//Class�� �Ҵ�ް� �Է¹��� input�� �°� �ʱ�ȭ
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


	
	Load_subject("����")
		-> ��ũ

	char* name;
	char* zoomAdd;
	DateTime startTime;

	subject
    {
		"����": "www.zoom.com",
		"����": "www.zoom.com"
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