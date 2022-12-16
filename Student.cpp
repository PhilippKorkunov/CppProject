#include "Student.h"
#include <iostream>

string Student::GetStatus()
{
	return string("Студент");
}

string Student::GetFullInfo()
{
	string out_str = "\n---------------------------\n";
	out_str += "Статус: " + Student::GetStatus() + "\n";
	out_str += Person::GetFullInfo();
	out_str += "Курс: " + std::to_string(this->student_year) + "\n";
	out_str += "Средняя оценка: " + std::to_string(this->average_mark) + "\n";
	return out_str;
}


string Student::additionalFields[] = { "Курс", "Средняя оценка" };
string* Student::allFields = Person::GetFullFeilds(Student::additionalFields, 2);

int Student::GetSizeOfAdditionalFields() {
	return sizeof(additionalFields) / sizeof(additionalFields[0]);
}

