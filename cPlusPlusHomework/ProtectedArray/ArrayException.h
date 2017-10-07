#pragma once

#include <iostream>

class ArrayException : public std::exception {
	const char* what() const throw() {
		return "Protected array out of bounds";
	}
};