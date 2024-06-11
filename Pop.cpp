#include "Pop.h"

Pop::Pop(double money, int happiness) {
	this->happiness = happiness;
	this->money = money;
	this->goods["food"] = 2;
}

int Pop::getGoodAmount(std::string good) {
	if (this->goods.count(good) == 0) {
		return 0;
	}
	int output = this->goods[good];
	return output;
}

double Pop::getMoney() {
	return this->money;
}

int Pop::getHappiness() {
	return this->happiness;
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
	return needsUnmet;
}
