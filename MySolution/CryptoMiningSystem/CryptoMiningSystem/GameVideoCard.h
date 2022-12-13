#pragma once
#include "VideoCard.h"
#include <iostream>

class GameVideoCard : public VideoCard
{
private:
	GameVideoCard();

	friend class Computer;
public:
	GameVideoCard(std::string model, float price, int generation, int ram);
	GameVideoCard(const GameVideoCard& gvc); // Copy

	friend std::ostream& operator<<(std::ostream& os, const GameVideoCard& gvc)
	{
		return os << "GameVideoCard("
			<< gvc.model << ", "
			<< gvc.price << ", "
			<< gvc.generation << ", "
			<< gvc.life_working_hours << ", "
			<< gvc.ram << ", "
			<< gvc.mined_money_per_hour << ")";
	}

};

