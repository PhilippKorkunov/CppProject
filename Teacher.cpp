#include "Teacher.h"
#include<iostream>

string Teacher::GetStatus()
{
	return "Преподаватель";
}

string Teacher::GetFullInfo()
{
	string out_str = "\n---------------------------\n";
	out_str += "Статус: " + Teacher::GetStatus() + "\n";
	out_str += Person::GetFullInfo();
	out_str += "Предмет: " + subject + "\n";
	out_str += "Стаж: " + std::to_string(experience) + "\n";
	return out_str;
}

string Teacher::additionalFields[] = { "Предмет", "Стаж", };
string* Teacher::allFields = Person::GetFullFeilds(Teacher::additionalFields, 2);

int Teacher::GetSizeOfAdditionalFields() {
	return sizeof(additionalFields) / sizeof(additionalFields[0]);
}
