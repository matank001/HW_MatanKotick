#include <iostream>

#include "Drink.h"
#include "Beer.h"
#include "WhiteWine.h"
#include "RedWine.h"

#define SHELF_SIZE 10

void print_shelf_menu(Drink** stock, int size) {
	std::cout << "(0) options\n";
	for (int i = 0; i < size; i++) {
		std::cout << "(" << i + 1 << ") " << stock[i]->getName() << "\n";
	}
	std::cout << "(99) How did you prepare my last drink?\n";
	std::cout << "(100) Exit\n";
}

int main()
{
	Drink* stock[SHELF_SIZE];

	stock[0] = new Beer("Goldstar");
	stock[1] = new Beer("Heinken");
	stock[2] = new Beer("Maccabi");
	stock[3] = new Beer("Tuborg");

	stock[4] = new WhiteWine("Carmel Emrald", 1990);
	stock[5] = new WhiteWine("Golan Smadar", 1989);
	stock[6] = new WhiteWine("Yarden Shardone", 2016);

	stock[7] = new RedWine("Kianty", 1920);
	stock[8] = new RedWine("Yarden Har Harmon Red", 2015);
	stock[9] = new RedWine("chadeau", 1953);

	bool inBar = true;
	int choice;
	Drink* lastDrink = nullptr;

	while (inBar) {
		std::cout << "What can I get you, sir? (0 - options)\n";
		std::cin >> choice;

		if (choice == 0) {
			print_shelf_menu(stock, SHELF_SIZE);
		}
		else if (choice == 99) {
			if (lastDrink != nullptr) {
				std::cout << lastDrink->prepare() << "\n";
			}
		}
		else if (choice == 100) {
			std::cout << "GoodBye!\n";
			inBar = false;
		}
		else {
			if (choice >= 1 && choice < SHELF_SIZE) {
				std::cout << "One " + stock[choice - 1]->getName() + " is coming up, sir\n";
				lastDrink = stock[choice - 1];
			}
		}
	}

	for (int i = 0; i < SHELF_SIZE; i++) {
		delete stock[i];
	}

    return 0;
}

