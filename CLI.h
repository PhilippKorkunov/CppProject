#pragma once
#include <string>
#include "Container.h"

class CLI
{
public:
	CLI();

private:
	bool isRan;
	std::string comfirmDescription;

	Container container;

	std::string ShowPossibleVariants(const std::string* possibleAnswers, int length, const std::string question);
	void CreatePerson();
	bool Comfirm(const std::string question);

};

