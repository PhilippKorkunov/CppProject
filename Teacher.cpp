#include "Teacher.h"
#include<iostream>

string Teacher::GetStatus()
{
	return "�������������";
}

string Teacher::GetFullInfo()
{
	string out_str = "\n---------------------------\n";
	out_str += "������: " + Teacher::GetStatus() + "\n";
	out_str += Person::GetFullInfo();
	out_str += "�������: " + subject + "\n";
	out_str += "����: " + std::to_string(experience) + "\n";
	return out_str;
}

string Teacher::additionalFields[] = { "�������", "����", };
string* Teacher::allFields = Person::GetFullFeilds(Teacher::additionalFields, 2);

int Teacher::GetSizeOfAdditionalFields() {
	return sizeof(additionalFields) / sizeof(additionalFields[0]);
}
