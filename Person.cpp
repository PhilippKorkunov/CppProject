#include "Person.h"
#include <iostream>

string Person::fields[] = { "�������", "���", "��������", "����� ��������", "����������� �����", "������������� �������" };

std::string Person::GetFullInfo()
{
	std::string out_str = "���: " + this->surname + " " + this->name + " " + this->patronymic + "\n";
	out_str += "����� ��������: " + this->phone_number + "\n";
	out_str += "Email: " + this->email + "\n";
	out_str += "������������� �������: " + this->degree + "\n";
	return out_str;
}





Person::Person(string surname, string name, string patronymic, string phone_number, string email, string degree)
{
	this->email = email;
	this->name = name;
	this->patronymic = patronymic;
	this->phone_number = phone_number;
	this->surname = surname;
	this->degree = degree;
}

string* Person::GetFullFeilds(string* addArray, int addArrLength)
{
	int fieldsSize = GetSizeOfFields();
	string* allFields = new string[fieldsSize + addArrLength];
	int i = 0;
	for (i = 0; i < fieldsSize; i++) {
		if (i < fieldsSize) {
			allFields[i] = fields[i];
		}
	}

	for (string* q = addArray; q != addArray + addArrLength; q++)
	{
		allFields[i] = *q;
		i++;
	}

	return allFields;
}

int Person::GetSizeOfFields()
{
	return 	sizeof(fields) / sizeof(fields[0]);
}