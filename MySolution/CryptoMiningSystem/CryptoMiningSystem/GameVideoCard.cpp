#include "GameVideoCard.h"
#include <iostream>

GameVideoCard::GameVideoCard(std::string model, float price, int generation, int ram)
	: VideoCard(model, price, generation, ram)
{
	if (generation > 9) {
		throw std::invalid_argument("generation");
	}

	this->mined_money_per_hour += this->mined_money_per_hour; // 100% increase
}

GameVideoCard::GameVideoCard(const GameVideoCard& gvc)
	: GameVideoCard(gvc.model, gvc.price, gvc.generation, gvc.ram)
{
	this->mined_money_per_hour = gvc.mined_money_per_hour;

	std::cout << "GameVideoCard '" << GetModel() << "' - copy constructor" << std::endl;
}

//std::ostream& GameVideoCard::operator<<(std::ostream& os)
//{
//	return os << "GameVideoCard("
//		<< model << ", "
//		<< price << ", "
//		<< generation << ", "
//		<< life_working_hours << ", "
//		<< ram << ", "
//		<< mined_money_per_hour << ")";
//}

