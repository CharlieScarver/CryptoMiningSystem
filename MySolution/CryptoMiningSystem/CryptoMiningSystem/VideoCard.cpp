#include "VideoCard.h"
#include <iostream>

VideoCard::VideoCard(std::string model, float price, int generation, int ram)
	: Component(model, price, generation, ram * generation * 10)
{
	if (ram <= 0 || ram > 32) {
		throw std::invalid_argument("ram");
	}

	this->ram = ram;
	this->mined_money_per_hour = static_cast<float>(ram) * generation / 10;

	this->dynamic_data = new int;
	*this->dynamic_data = 5;
}

VideoCard::VideoCard(const VideoCard& vc)
	: VideoCard(vc.model, vc.price, vc.generation, vc.ram)
{
	mined_money_per_hour = vc.mined_money_per_hour;

	std::cout << "VideoCard '" << GetModel() << "' - copy constructor" << std::endl;
}

VideoCard::VideoCard(VideoCard&& vc)
	: VideoCard(vc.model, vc.price, vc.generation, vc.ram)
{
	mined_money_per_hour = vc.mined_money_per_hour;

	this->dynamic_data = vc.dynamic_data;
	vc.dynamic_data = nullptr;

	std::cout << "VideoCard '" << GetModel() << "' - move constructor" << std::endl;
}

VideoCard::~VideoCard()
{
	free(dynamic_data);
}

VideoCard& VideoCard::operator+=(int n)
{
	int new_ram = ram + n;
	if (new_ram <= 0 || new_ram > 32) {
		throw std::invalid_argument("ram");
	}

	ram = new_ram;

	return *this;
}

bool VideoCard::operator==(const VideoCard& rhs)
{
	return model == rhs.GetModel() &&
		price == rhs.GetPrice() &&
		generation == rhs.GetGeneration() &&
		life_working_hours == rhs.GetLifeWorkingHours() &&
		ram == rhs.GetRam() &&
		mined_money_per_hour == rhs.GetMinedMoneyPerHour();
}

std::ostream& VideoCard::operator<<(std::ostream& os)
{
	return os << "VideoCard("
		<< model << ", "
		<< price << ", "
		<< generation << ", "
		<< life_working_hours << ", "
		<< ram << ", "
		<< mined_money_per_hour << ")";
}

int VideoCard::GetRam() const
{
	return ram;
}

float VideoCard::GetMinedMoneyPerHour() const
{
	return mined_money_per_hour;
}
