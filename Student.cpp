#include "Student.h"
#include <iostream>

string Student::GetStatus()
{
	return string("�������");
}

string Student::GetFullInfo()
{
	string out_str = "\n---------------------------\n";
	out_str += "������: " + Student::GetStatus() + "\n";
	out_str += Person::GetFullInfo();
	out_str += "����: " + std::to_string(this->student_year) + "\n";
	out_str += "������� ������: " + std::to_string(this->average_mark) + "\n";
	return out_str;
}


string Student::additionalFields[] = { "����", "������� ������" };
string* Student::allFields = Person::GetFullFeilds(Student::additionalFields, 2);

int Student::GetSizeOfAdditionalFields() {
	return sizeof(additionalFields) / sizeof(additionalFields[0]);
}

