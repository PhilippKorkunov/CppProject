#pragma once
#include <list>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out;          // ����� ��� ������
	out.open("D:\\hello.txt"); // �������� ���� ��� ������
	if (out.is_open())
	{
		out << "Hello World!" << std::endl;
	}

	std::cout << "End of program" << std::endl;
	return 0;
}

class Container
{
public:
	Container();

	list<Student> studentList;
	list<Teacher> teacherList;

	void AddPerson(Student student);
	void AddPerson(Teacher teacher);

	std::string GetFullInfo();

	void ConvertToTxt();

	~Container();

private:
};

