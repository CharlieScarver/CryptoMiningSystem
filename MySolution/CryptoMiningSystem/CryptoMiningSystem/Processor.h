#pragma once
#include "Component.h"

// Public inheritance in C++ is like
// normal inheritance in other languages
// Public members remain public
// Protected members remain protected
// Private members remain private

class Processor : public Component
{
private:
	Processor();
protected:
	int mine_multiplier;

	Processor(std::string model, float price, int generation, int life_working_hours, int mine_multiplier);
public:
	Processor(const Processor& cpu); // Copy
	Processor(Processor&& cpu); // Move

	int GetMineMultiplier() const;
};
