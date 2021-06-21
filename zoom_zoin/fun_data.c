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

const char* Load_Timetable(int ToDay)
{

	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("timetable.json");
	rootObject = json_value_get_object(rootValue);



	const char* retval = json_object_get_string(rootObject, json_object_get_name(rootObject, ToDay));

	//json_value_free(rootValue);

	return retval;
}

const char* Load_Subject(const char * subject_name)
{

	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("subject.json");
	rootObject = json_value_get_object(rootValue);


	const char* retval = json_object_get_string(rootObject, subject_name);

	//json_value_free(rootValue);
	return retval;
}

const char* loadSubjectObbject(int i)
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("subject.json");
	rootObject = json_value_get_object(rootValue);


	const char* retval = json_object_get_name(rootObject, i);
	//json_value_free(rootValue);

	return retval;
}

const char* Load_timetable_week(int i, int num)
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("timetable_week.json");
	rootObject = json_value_get_object(rootValue);
	
	//printf("%s", json_object_get_name(rootObject, i));

	JSON_Array* array = json_object_get_array(rootObject, json_object_get_name(rootObject, i));

	const char* retval = json_array_get_string(array, num);
	//json_value_free(rootValue);

	return retval;
}