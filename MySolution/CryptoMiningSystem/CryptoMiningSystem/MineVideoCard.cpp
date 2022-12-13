#include "MineVideoCard.h"

MineVideoCard::MineVideoCard(std::string model, float price, int generation, int ram)
	: VideoCard(model, price, generation, ram)
{
	if (generation > 6) {
		throw std::invalid_argument("generation");
	}

	this->mined_money_per_hour += 7 * this->mined_money_per_hour; // 700% increase
	this->life_working_hours += this->life_working_hours; // 100% increase
}
