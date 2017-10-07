#pragma once

#include <iostream>
#include <string>
#include <math.h>

class Fraction {

public:
	Fraction(int nom) : _nom(nom), _den(1) {}
	Fraction(int nom, int den);
	~Fraction() {}

	std::string to_string();

	Fraction operator* (const Fraction other) const;
	Fraction operator*= (const Fraction other);

	Fraction operator/ (const Fraction other) const;
	Fraction operator/= (const Fraction other);

	Fraction operator+ (const Fraction other) const;
	Fraction operator+= (const Fraction other);

	Fraction operator- (const Fraction other) const;
	Fraction operator-= (const Fraction other);

	Fraction operator- () { return *this * Fraction(-1); }

	operator float() const;


private:
	int _nom;
	int _den;
	int _gcd(int num1, int num2); //greatest common divisor
};
