#include "LowPerfProcessor.h"

LowPerfProcessor::LowPerfProcessor(std::string model, float price, int generation, int life_working_hours)
	: Processor(model, price, generation, life_working_hours, 2)
{}
