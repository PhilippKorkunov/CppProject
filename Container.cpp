#include "Container.h"
#include <list>
#include <fstream>

Container::Container()
{

}

void Container::AddPerson(Student student)
{
	this->studentList.push_back(student);
}

void Container::AddPerson(Teacher teacher)
{
	this->teacherList.push_back(teacher);
}

std::string Container::GetFullInfo()
{
	std::string out_str = "";
	for (Student student : studentList) {
		out_str += student.GetFullInfo() + "\n";
	}

	for (Teacher teacher : teacherList) {
		out_str += teacher.GetFullInfo() + "\n";
	}

	return out_str;
}

void Container::ConvertToTxt()
{
	std::string info = this->GetFullInfo();

	std::ofstream out;          // поток для записи
	out.open("D:\\final.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << info << std::endl;
	}
	out.close();
}

Container::~Container()
{
	//this->personList.clear();
}
