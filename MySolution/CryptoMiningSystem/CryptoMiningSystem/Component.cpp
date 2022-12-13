#include "Component.h"
#include <iostream>

Component::Component()
{
	throw std::logic_error("Empty constructor is restricted");
}

Component::Component(std::string model, float price, int generation, int life_working_hours)
{
	if (model.empty()) {
		throw std::invalid_argument("model");
	}
	if (price < 0.001f || price > 10000.0f) {
		throw std::invalid_argument("price");
	}
	if (generation < 1) {
		throw std::invalid_argument("generation");
	}

	this->model = model;
	this->price = price;
	this->generation = generation;
	this->life_working_hours = life_working_hours;
}

Component::~Component()
{
	std::cout << "Component '" << GetModel() << "' was destroyed" << std::endl;
}

std::string Component::GetModel() const
{
	return model;
}

float Component::GetPrice() const
{
	return price;
}

int Component::GetGeneration() const
{
	return generation;
}

int Component::GetLifeWorkingHours() const
{
	return life_working_hours;
}
