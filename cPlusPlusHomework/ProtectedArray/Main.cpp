#include <iostream>
#include "Array.h"
#include "Var.h"

int main()
{
	Array<int> ar1(10);

	for (int i = 0; i < 10; i++) {
		ar1[i] = i;
	}

	Var<int>* k = &(ar1[8]);
	k++; k++;
	try {
		int f = **k;
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << ar1[2] << '\n';
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
    return 0;
}

