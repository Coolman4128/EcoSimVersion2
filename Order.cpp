#include "Order.h"
#include "Pop.h"

Order::Order(double price, std::string good, int quantity, Pop* seller) {
	this->price = price;
	this->good = good;
	this->quantity = quantity;
	this->seller = seller;
}

int Order::fillOrder(Pop* buyer, int quantity) {
	if (buyer->getMoney() < this->price) {
		return 0;
	}
	else if (quantity > this->quantity) {
		return fillOrder(buyer, (this->quantity));
	}
	else if (buyer->getMoney() < this->getPrice() * quantity) {
		int newQuantity = buyer->getMoney() / this->getPrice();
		return fillOrder(buyer, newQuantity);
	}
	this->seller->pay(this->price * quantity);
	buyer->spend(this->price * quantity);
	buyer->giveGood(this->good, quantity);
	this->quantity = this->quantity - quantity;
	return quantity;
}

double Order::getPrice() {
	return this->price;
}

std::string Order::getGood() {
	return this->good;
}

int Order::getQuantity() {
	return this->quantity;
}

Pop* Order::getSeller() {
	return this->seller;
}

void Order::returnOrder() {
	this->seller->giveGood(this->good, this->quantity);
	this->quantity = 0;
}
