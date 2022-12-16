#pragma once
#include <list>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>


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

