#pragma once

#include "Drink.h"

class Beer : public Drink {
public:
	Beer(std::string name) : Drink(name) {}

	std::string prepare() override{
		return "pour it into the glass";
	}
};