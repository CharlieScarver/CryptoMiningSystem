#include "User.h"

User::User(std::string name, int stars, float money, Computer* computer)
{
	if (name.empty()) {
		throw std::invalid_argument("name");
	}
	if (money < 0) {
		throw std::invalid_argument("money");
	}

	this->name = name;
	this->money = money;
	this->computer = computer;

	this->stars = money / 100;
}
