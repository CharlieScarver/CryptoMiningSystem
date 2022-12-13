#pragma once
#include <string>
#include <stdexcept>

class Component
{
private:
	Component();
protected:
	std::string model;
	float price;
	int generation;
	int life_working_hours;

	Component(std::string model, float price, int generation, int life_working_hours);
public:
	~Component();

	std::string GetModel() const;
	float GetPrice() const;
	int GetGeneration() const;
	int GetLifeWorkingHours() const;
};
