#pragma once

#include "Drink.h"

class Wine : public Drink {
public:
	Wine(std::string name, int year) : Drink(name), _year(year) {}
	std::string getName() {
		return _name + " (year " + std::to_string(_year) + ")";
	}
protected:
	int _year;
};