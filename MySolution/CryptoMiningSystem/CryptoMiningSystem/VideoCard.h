#pragma once
#include "Component.h"

class VideoCard : public Component
{
private:
	VideoCard();
protected:
	int ram;
	float mined_money_per_hour;
	int* dynamic_data;

	VideoCard(std::string model, float price, int generation, int ram);
public:
	VideoCard(const VideoCard& video_card); // Copy
	VideoCard(VideoCard&& video_card); // Move
	~VideoCard();

	VideoCard& operator+=(int n);
	bool operator==(const VideoCard& rhs);
	std::ostream& operator<<(std::ostream& os);

	int GetRam() const;
	float GetMinedMoneyPerHour() const;
};

