#pragma once
#include "Computer.h"
#include <string>

class User
{
private:
	User();
protected:
	std::string name;
	int stars;
	float money;
	Computer* computer;
public:
	User(std::string name, int stars, float money, Computer* computer);
	~User();
};
