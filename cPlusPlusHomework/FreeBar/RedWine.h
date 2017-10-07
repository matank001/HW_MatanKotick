#pragma once

#include "Wine.h"

class RedWine : public Wine {
public:
	RedWine(std::string name, int year) : Wine(name, year) {}
	std::string prepare() override {
		return "served in 16-18 degrees";
	}
};