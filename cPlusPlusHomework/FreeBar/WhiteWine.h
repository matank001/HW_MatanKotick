#pragma once

#include "Wine.h"

class WhiteWine : public Wine {
public:
	WhiteWine(std::string name, int year) : Wine(name, year) {}
	std::string prepare() override {
		return "served colddd";
	}
};