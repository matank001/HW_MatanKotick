#include "Fraction.h"

Fraction::Fraction(int nom, int den) {
	if (nom < 0 && den < 0) {
		nom = nom * -1;
		den = den * -1;
	}

	if (den == 0) {
		throw "divide by zero";
	}

	int gcd = _gcd(nom, den);
	_nom = nom / gcd;
	_den = den / gcd;
}

std::string Fraction::to_string() {
	return std::to_string(_nom) + "/" +std::to_string(_den);
}

Fraction Fraction::operator*(const Fraction other) const
{
	return Fraction(_nom * other._nom, _den * other._den);
}

Fraction Fraction::operator*=(const Fraction other)
{
	Fraction new_frac =  *this * other;
	
	_nom = new_frac._nom;
	_den = new_frac._den;

	return new_frac;
}

Fraction Fraction::operator/(const Fraction other) const
{
	return *this * Fraction(other._den, other._nom);
}

Fraction Fraction::operator/=(const Fraction other)
{
	Fraction new_frac = *this / other;
	_nom = new_frac._nom;
	_den = new_frac._den;
	return new_frac;
}

Fraction Fraction::operator+(const Fraction other) const
{
	return Fraction(_nom * other._den + other._nom * _den, _den * other._den);
}

Fraction Fraction::operator+=(const Fraction other)
{
	Fraction new_frac = *this + other;
	_nom = new_frac._nom;
	_den = new_frac._den;
	return new_frac;
}

Fraction Fraction::operator-(const Fraction other) const
{
	return *this + Fraction(-other._nom, other._den);
}

Fraction Fraction::operator-=(const Fraction other)
{
	Fraction new_frac = *this - other;
	_nom = new_frac._nom;
	_den = new_frac._den;
	return new_frac;
}

Fraction::operator float() const
{
	return _nom / (float)_den;
}

int Fraction::_gcd(int num1, int num2)
{
	num1 = abs(num1);
	num2 = abs(num2);
	
	int low = fmax(num1, num2);
	int curr_div = 1;

	for (int i = 1; i <= low; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			curr_div = i;
		}
	}

	return curr_div;
}
