#pragma once
#include "Person.h"

using namespace std;

class Teacher : public Person
{
public:

	Teacher(string surname, string name, string patronymic, string phone_number, string email, string degree, string subject, int experience) :
		Person(surname, name, patronymic, phone_number, email, degree), subject(subject), experience(experience) {};

	string GetStatus() override;
	string GetFullInfo() override;

	static string* allFields;

	static int GetSizeOfAdditionalFields();



private:
	int experience;
	string subject;

	static string additionalFields[];
};

