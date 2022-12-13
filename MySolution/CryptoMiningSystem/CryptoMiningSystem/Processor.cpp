#include "Processor.h"
#include <iostream>

Processor::Processor(std::string model, float price, int generation, int life_working_hours, int mine_multiplier)
	: Component(model, price, generation, life_working_hours)
{
	if (generation > 9) {
		throw std::invalid_argument("generation");
	}

	this->mine_multiplier = mine_multiplier;
}

Processor::Processor(const Processor& cpu)
	: Processor(cpu.model, cpu.price, cpu.generation, cpu.life_working_hours, cpu.mine_multiplier)
{
	std::cout << "Processor '" << GetModel() << "' - copy constructor" << std::endl;
}

Processor::Processor(Processor&& cpu)
	: Processor(cpu.model, cpu.price, cpu.generation, cpu.life_working_hours, cpu.mine_multiplier)
{
	std::cout << "Processor '" << GetModel() << "' - move constructor" << std::endl;
}

int Processor::GetMineMultiplier() const
{
	return mine_multiplier;
}

bool operator==(const Processor& lhs, const Processor& rhs)
{
	return lhs.GetModel() == rhs.GetModel() &&
			lhs.GetPrice() == rhs.GetPrice() &&
			lhs.GetGeneration() == rhs.GetGeneration() &&
			lhs.GetLifeWorkingHours() == rhs.GetLifeWorkingHours() &&
			lhs.GetMineMultiplier() == lhs.GetMineMultiplier();
}