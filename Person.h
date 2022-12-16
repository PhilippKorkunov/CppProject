#pragma once
#include <string>

using namespace std;

class Person
{
public:
	static string fields[];

	virtual string GetFullInfo();
	virtual string GetStatus() = 0;


	Person(string surname, string name, string patronymic, string phone_number, string email, string degree);

	static string* GetFullFeilds(string* addArray, int addArrLength);
	static int GetSizeOfFields();

private:
	string name;
	string surname;
	string patronymic;
	string phone_number;
	string email;
	string degree;

	//virtual void AddNewFieldsToList() = 0;
};

