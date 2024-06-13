#include "Pop.h"
#include "Market.h"
#include <iostream>
#include "Market.h"
#include "MarketData.h"

Pop::Pop(double money, int happiness, std::string job, std::string ID, Market* market = NULL) {
	this->market = market;
	this->happiness = happiness;
	this->money = money;
	this->goods["food"] = 3;
	this->goods["wool"] = 3;
	this->job = job;
	this->needs["food"] = 3;
	this->needs["wool"] = 3; //sometime soon change this to a loop that adds 3 needs to all goods in Pop::GOODS
	this->ID = ID;
}

const int Pop::NEEDS = 3;

const std::string Pop::GOODS[] = { "food", "wool" };

int Pop::getGoodAmount(std::string good) {
	if (this->goods.count(good) == 0) {
		return 0;
	}
	int output = this->goods[good];
	return output;
}

int Pop::getNeedsWithGood(std::string good) {
	if (this->needs.count(good) == 0) {
		return 0;
	}
	int output = this->needs[good];
	return output;
}

double Pop::getMoney() {
	return this->money;
}

int Pop::getHappiness() {
	return this->happiness;
}

Market* Pop::getMarket() {
	return this->market;
}

double Pop::pay(double amount) {
	this->money = this->money + amount;
	return this->money;
}

double Pop::spend(double amount) {
	if (this->money < amount) {
		return -1;
	}
	this->money = this->money - amount;
	return this->money;
}

int Pop::giveGood(std::string good, int quantity) {
	if (this->goods.count(good) == 0) {
		this->goods[good] = quantity;
	}
	else {
		this->goods[good] = this->goods[good] + quantity;
	}
	return this->goods[good];
}

int Pop::submitOrder(std::string good, double price, int quantity) {
	if (this->market == NULL) {
		return -1;
	}
	else if (this->goods.count(good) == 0) {
		return -1;
	}
	else if (this->goods[good] < quantity) {
		return -1;
	}
	this->market->createOrder(price, good, quantity, this);
	this->goods[good] = this->goods[good] - quantity;
	return quantity;
}

int Pop::supplyNeeds() {
	for (std::map<std::string, int>::iterator itr = this->needs.begin(); itr != this->needs.end(); ++itr) {
		if (this->goods.count(itr->first) > 0 && itr->second > 0) {
			if (this->goods[itr->first] > itr->second) {
				this->goods[itr->first] = this->goods[itr->first] - itr->second;
				this->needs[itr->first] = 0;
			}
			else {
				this->needs[itr->first] = this->needs[itr->first] - this->goods[itr->first];
				this->goods[itr->first] = 0;
			}
		}
		else {
			continue;
		}
	}
	return 1;
}

int Pop::calculateHappiness() {
	int needsUnmet = 0;
	for (std::map<std::string, int>::iterator itr = this->needs.begin(); itr != this->needs.end(); ++itr) {
		needsUnmet = needsUnmet + itr->second;
	}
	if (needsUnmet > 7) {
		this->happiness = this->happiness - 2;
	}
	else if (needsUnmet > 4) {
		this->happiness = this->happiness - 1;
	}
	else if (needsUnmet > 2) {
		
	}
	else if (needsUnmet > 0) {
		this->happiness = this->happiness + 1;
	}
	else {
		this->happiness = this->happiness + 2;
	}

	if (this->happiness > 5) {
		this->happiness = 5;
	}
	else if (this->happiness < -5) {
		this->happiness = -5;
	}
	return needsUnmet;
}

int Pop::resetNeeds() {
	for (std::map<std::string, int>::iterator itr = this->needs.begin(); itr != this->needs.end(); ++itr) {
		this->needs[itr->first] = Pop::NEEDS;
	}
	return 1;
}

int Pop::work() {
	int happinessConstant = 1;
	if (this->happiness < -2) {
		happinessConstant = 1;
	}
	else if (this->happiness < 0) {
		happinessConstant = 2;
	}
	else if (this->happiness < 3) {
		happinessConstant = 3;
	}
	else if (this->happiness < 5) {
		happinessConstant = 4;
	}
	else {
		happinessConstant = 5;
	}
	if (this->job == "farmer") {
		this->goods["food"] = this->goods["food"] + happinessConstant;
	}
	else if (this->job == "rancher") {
		this->goods["wool"] = this->goods["wool"] + happinessConstant;
	}
	else {
		return 0;
	}
	return 1;
}

void Pop::Tick() {
	work();
	supplyNeeds();
	calculateHappiness();
	resetNeeds();
}

int Pop::buyDecision() {
	//This function will be used to determine if a pop wants to buy something. There are 3 main criteria that will be used to determine if a pop wants to buy something:
	//1. The pop needs the good, and will attempt to buy it if they do not have enough of it.
	//2. The pop sees the price of the good is lower than normal and will buy it if they have enough money.
	//3. The pop has an abundance of money


	double costOfLiving = this->getMarket()->getMarketData()->getPriceAverage() * Pop::NEEDS * 5; // change this to a loop that adds the average price of all goods in Pop::GOODS. The 5 comes from 5 ticks.
	
	if (this->getNeedsWithGood("food") > 0) {
		//submit an order to buy food for how much is needed
	}
	else if (this->getMoney() > costOfLiving) {
		double remainingMoney = this->getMoney() - costOfLiving;
		//submit an order to buy food for how much money is left over
	}
	

	return 1;
}

int Pop::sellDecision() {
	//This function will be used to determine if a pop wants to sell something. There are 3 main criteria that will be used to determine if a pop wants to sell something:
	//1. The pop has an abundance of the good.
	//2. The pop needs money.
	//3. The pop sees the price of the good is higher than normal.
	return 1;
}

int Pop::endTick() {
	return 1;
}

void Pop::printPopInfo() {
	std::cout << "Money: " << this->money << std::endl;
	std::cout << "Happiness: " << this->happiness << std::endl;
	std::cout << "Job: " << this->job << std::endl;
	std::cout << "Goods: " << std::endl;
	for (std::map<std::string, int>::iterator itr = this->goods.begin(); itr != this->goods.end(); ++itr) {
		std::cout << itr->first << ": " << itr->second << std::endl;
	}
	std::cout << "Needs: " << std::endl;
	for (std::map<std::string, int>::iterator itr = this->needs.begin(); itr != this->needs.end(); ++itr) {
		std::cout << itr->first << ": " << itr->second << std::endl;
	}
}