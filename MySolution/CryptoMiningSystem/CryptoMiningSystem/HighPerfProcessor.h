#pragma once
#include "Processor.h"

class HighPerfProcessor : public Processor
{
private:
	HighPerfProcessor();
public:
	HighPerfProcessor(std::string model, float price, int generation, int life_working_hours);
};
