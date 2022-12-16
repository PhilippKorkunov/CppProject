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
	//std::string info = this->GetFullInfo();

	//std::ifstream file("D:\\Final - master\\TxtDir"); // окрываем файл для чтения
	//if (file.is_open())
	//{
	//	while (std::getline(file, info))
	//	{
	//		std::cout << info << std::endl;
	//	}
	//}
	//file.close();
}

Container::~Container()
{
	//this->personList.clear();
}
