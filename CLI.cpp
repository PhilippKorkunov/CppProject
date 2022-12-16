#include "CLI.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Student.h"
#include "Teacher.h"



CLI::CLI()
{
	isRan = true;

	comfirmDescription = " Y - да, N - нет";

	std::cout << "Добро пожаловать!" << std::endl;

	std::string possibleAnswers[4]{ "Q", "S", "A", "C" };
	int length = sizeof(possibleAnswers) / sizeof(possibleAnswers[0]);
	std::string question = "Что вы хотите сделать? (Введите соответсвующую букву): \n\tA - добавить персону \n\tS - посмотреть информацию о персонах";
	question += "\n\tC - Конвертировать информацию о персонах в txt \n\tQ - Завершить работу";

	while (isRan) {
		std::string variant = this->ShowPossibleVariants(possibleAnswers, length, question);

		if (variant == "Q") {
			isRan = !Comfirm("Вы действительно хотите выйти?");
		}
		else if (variant == "A") {
			CreatePerson();
		}
		else if (variant == "S") {
			cout << container.GetFullInfo();
		}
		else if (variant == "C") {
			container.ConvertToTxt();
		}
	}
}

std::string CLI::ShowPossibleVariants(const std::string* possibleAnswers, int length, const std::string question)
{
	while (true)
	{
		std::string in_str = "";
		std::cout << question << std::endl;
		std::getline(std::cin, in_str);

		for (int i = 0; i < length; i++)
		{
			if (boost::algorithm::to_lower_copy(in_str) == boost::algorithm::to_lower_copy(possibleAnswers[i])) {
				return possibleAnswers[i];
			}
		}
		std::cout << "Команда не найдена. Попробуйте еще раз" << std::endl;
	}
}


bool CLI::Comfirm(const std::string question)
{
	std::cout << question << comfirmDescription << std::endl;
	while (true) {
		std::string in_str = "";
		std::getline(std::cin, in_str);
		if (boost::algorithm::to_lower_copy(in_str) == "y") {
			return true;
			break;
		}
		else if (boost::algorithm::to_lower_copy(in_str) == "n") {
			return false;
			break;
		}
		else
		{
			std::cout << "Введите один з 2 вариантов" << comfirmDescription << std::endl;
		}

	}
}

void CLI::CreatePerson()
{
	std::string possibleAnswers[2]{ "St", "T" };
	int length = sizeof(possibleAnswers) / sizeof(possibleAnswers[0]);
	std::string question = "Кого вы хотите добавить? (Введите соответсвующую букву): \n\tSt - Студента \n\tT - Преподавателя";
	std::string variant = ShowPossibleVariants(possibleAnswers, length, question);
	std::string* allFields = nullptr;
	int size;
	if (variant == "St") {
		allFields = Student::allFields;
		size = Student::GetSizeOfFields() + Student::GetSizeOfAdditionalFields();
	}
	else if (variant == "T") {
		allFields = Teacher::allFields;
		size = Teacher::GetSizeOfFields() + Teacher::GetSizeOfAdditionalFields();
	}
	else {
		return;
	}

	cout << endl << "-----------------------------------" << endl;
	cout << "Введите необходимые данные:" << endl;
	int i = 0;
	string personData[10];
	for (string* q = allFields; q != allFields + size; q++)
	{
		string str;
		cout << *q << ": ";
		std::getline(std::cin, str);
		personData[i] = str;
		i++;
	}

	try {
		if (variant == "St") {
			Student student = Student(personData[0], personData[1], personData[2], personData[3], personData[4], personData[5], std::stoi(personData[6]), stod(personData[7]));
			container.AddPerson(student);
		}
		else if (variant == "T") {
			Teacher teacher = Teacher(personData[0], personData[1], personData[2], personData[3], personData[4], personData[5], personData[6], stoi(personData[7]));
			container.AddPerson(teacher);
		}
	}
	catch (const std::exception& e) {
		cerr << (e.what()) << endl;
	}
}
