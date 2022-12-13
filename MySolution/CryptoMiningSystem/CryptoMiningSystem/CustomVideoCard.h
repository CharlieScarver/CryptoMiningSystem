#pragma once
#include "Processor.h"
#include "VideoCard.h"

class CustomVideoCard : public VideoCard, public Processor
{
private:
	CustomVideoCard();
public:
	CustomVideoCard(VideoCard* vc, Processor* cpu);

	std::string GetModel();
	float GetPrice();
};

