#include "Market.h"
#include "Pop.h"
#include "Order.h"
#include "MarketData.h"

Market::Market() {
	this->popCount = 0;
	this->marketData = new MarketData(this);
}

void Market::addPop(Pop* pop) {
	this->Pops.push_back(pop);
	this->popCount++;
}

void Market::createPop(double money, int happiness, std::string job) {
	std::string ID = std::to_string(this->popCount);
	Pop* newPop = new Pop(money, happiness, job, ID, this);
	this->addPop(newPop);
}

Order* Market::createOrder(double price, std::string good, int quantity, Pop* seller) {
	Order* newOrder = new Order(price, good, quantity, seller);
	this->addOrder(newOrder);
	return newOrder;
}

void Market::TickPops() {
	for (std::list<Pop*>::iterator it = this->Pops.begin(); it != this->Pops.end(); it++) {
		Pop* currentPop = *it;
		currentPop->Tick();
		currentPop->printPopInfo();
	}
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


MarketData* Market::getMarketData() {
	return this->marketData;
}
