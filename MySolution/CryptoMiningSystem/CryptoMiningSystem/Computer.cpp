#include "Computer.h"
#include <iostream>

Computer::Computer(Processor* processor, VideoCard* video_card, int ram)
{
	if (processor == nullptr) {
		throw std::invalid_argument("processor");
	}
	if (video_card == nullptr) {
		throw std::invalid_argument("video_card");
	}
	if (ram <= 0 || ram > 32) {
		throw std::invalid_argument("ram");
	}

	this->processor = processor;
	this->video_card = video_card;
	this->ram = ram;

	this->mined_amount_per_hour = processor->GetMineMultiplier() * video_card->GetMinedMoneyPerHour();
}

Computer::~Computer()
{
	std::cout << "Computer with components: '" << processor->GetModel() << "' and '" << video_card->GetModel() << "' was destroyed" << std::endl;
}

Processor* Computer::GetProcessor()
{
	return processor;
}

VideoCard* Computer::GetVideoCard()
{
	return video_card;
}

int Computer::GetRam()
{
	return ram;
}
