#include <stdio.h>
#include "parson.h"

int Load_Setting(int type)
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("settings.json");
	rootObject = json_value_get_object(rootValue);

	int retval = 0;

	if (type == 0)
		retval = (int)json_object_get_number(rootObject, "Browser");
	else if (type == 1)
		retval = (int)json_object_get_number(rootObject, "Wait_Min");

	json_value_free(rootValue);

	return retval;
}

int Load_Timetable(int ToDay)
{

	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("timetable.json");
	rootObject = json_value_get_object(rootValue);



	int retval = 0;

	if (ToDay == 1)
		retval = (int)json_object_get_number(rootObject, "Class_1");
	else if (ToDay == 2)
		retval = (int)json_object_get_number(rootObject, "Class_2");
	else if (ToDay == 3)
		retval = (int)json_object_get_number(rootObject, "Class_3");
	else if (ToDay == 4)
		retval = (int)json_object_get_number(rootObject, "Class_4");
	else if (ToDay == 5)
		retval = (int)json_object_get_number(rootObject, "Class_5");
	else if (ToDay == 6)
		retval = (int)json_object_get_number(rootObject, "Class_6");
	else if (ToDay == 7)
		retval = (int)json_object_get_number(rootObject, "Class_7");

	json_value_free(rootValue);

	return retval;
}

int Load_Subject(int type)
{

	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("subject.json");
	rootObject = json_value_get_object(rootValue);


	int retval = 0;

	if (type == 0)
		retval = (int)json_object_get_number(rootObject, "과학");
	else if (type == 1)
		retval = (int)json_object_get_number(rootObject, "수학");

	json_value_free(rootValue);

	return retval;
}
