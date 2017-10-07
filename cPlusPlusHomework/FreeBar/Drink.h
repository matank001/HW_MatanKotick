#pragma once

#include <iostream>
#include <string>

class Drink {
public:
	Drink(std::string name): _name(name) {}

	virtual std::string getName() {
		return _name;
	}
	virtual std::string prepare() = 0;

protected:
	std::string _name;
};