#pragma once
#include "Processor.h"
#include "VideoCard.h"

class Computer
{
private:
	Computer();
protected:
	// Components
	Processor* processor;
	VideoCard* video_card;
	int ram;

	float mined_amount_per_hour;

public:
	Computer(Processor *processor, VideoCard* video_card, int ram);
	~Computer();

	Processor* GetProcessor();
	VideoCard* GetVideoCard();
	int GetRam();
};
