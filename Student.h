#pragma once
#include "Person.h"

using namespace std;

class Student : public Person
{
public:

	Student(string surname, string name, string patronymic, string phone_number, string email, string degree, int student_year, double average_mark) :
		Person(surname, name, patronymic, phone_number, email, degree), student_year(student_year), average_mark(average_mark) {};

	string GetStatus() override;
	string GetFullInfo() override;

	static string* allFields;

	static int GetSizeOfAdditionalFields();

private:
	int student_year;
	double average_mark;
	static string additionalFields[];

	//void AddNewFieldsToList() override;
};

