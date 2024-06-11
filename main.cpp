#include <iostream>
#include "Pop.h"

int main() {
	Pop *cool = new Pop(100.25, 5);
	Pop *cool2 = new Pop(25.68, 4);
	std::cout << cool->getMoney() << std::endl;
	std::cout << cool2->getMoney() << std::endl;
	std::cout << cool->getHappiness() << std::endl;
	std::cout << cool2->getHappiness() << std::endl;
	std::cout << cool->getGoodAmount("food") << std::endl;
	std::cout << cool2->getGoodAmount("water") << std::endl;
	return 0;
}