#include "CustomVideoCard.h"

CustomVideoCard::CustomVideoCard(VideoCard* vc, Processor* cpu)
    : VideoCard(vc->GetModel(), vc->GetPrice(), vc->GetGeneration(), vc->GetRam()),
    Processor(cpu->GetModel(), cpu->GetPrice(), cpu->GetGeneration(), cpu->GetLifeWorkingHours(), cpu->GetMineMultiplier())
{
}

std::string CustomVideoCard::GetModel()
{
    return VideoCard::model;
    // return Processor::model;
}

float CustomVideoCard::GetPrice()
{
    return Processor::price;
}
