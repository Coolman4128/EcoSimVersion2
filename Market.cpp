#include "Market.h"
#include "Pop.h"


Market::Market() {
	this->popCount = 0;
}

void Market::addPop(Pop* pop) {
	this->Pops.push_back(pop);
	this->popCount++;
}

void Market::createPop(double money, int happiness, std::string job) {
	std::string ID = std::to_string(this->popCount);
	Pop* newPop = new Pop(money, happiness, job, ID);
	this->addPop(newPop);
}

void Market::addOrder(Order* order) {
	this->Orders.push_back(order);
}

void Market::removePop(Pop* pop) {
	this->Pops.remove(pop);
	this->popCount--;
}

void Market::removeOrder(Order* order) {
	this->Orders.remove(order);
}

