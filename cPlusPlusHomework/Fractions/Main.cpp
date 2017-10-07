// cPlusPlusHomework.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Fraction.h"

int main()
{
	Fraction f1(5, 2);
	Fraction f2(8, 4);

	Fraction f3 = f1 * f2;

	std::cout << f3.to_string() << "\n";

    return 0;
}