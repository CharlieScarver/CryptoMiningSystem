#pragma once
#include "Processor.h"

class LowPerfProcessor : public Processor
{
private:
	LowPerfProcessor();
public:
	LowPerfProcessor(std::string model, float price, int generation, int life_working_hours);
};
