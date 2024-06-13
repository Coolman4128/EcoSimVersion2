#include "MarketData.h"
#include "Market.h"

// This constructor will initialize the market data.
MarketData::MarketData(Market* market) {
	this->priceAverage = 1;
	this->transactionsPerTick = 0;
	this->goodsSoldPerTick = 0;
	this->market = market;
}


// This function will return the price average.
double MarketData::getPriceAverage() {
	double output = this->priceAverage;
	return output;
}


// This function will return the number of transactions per tick.
int MarketData::getTransactionsPerTick() {
	int output = this->transactionsPerTick;
	return output;
}


// This function will return the number of goods sold per tick.
int MarketData::getGoodsSoldPerTick() {
	int output = this->goodsSoldPerTick;
	return output;
}


// This function will update the price average by taking the average of the current price and the previous price.
double MarketData::updatePriceAverage(double price) {
	double output = this->priceAverage;
	output = (output + price) / 2;
	this->priceAverage = output;
	return output;
}

int MarketData::clearTickData() {
	this->transactionsPerTick = 0;
	this->goodsSoldPerTick = 0;
	return 1;
}

int MarketData::addTransaction() {
	this->transactionsPerTick++;
	return 1;
}

int MarketData::addGoodsSold(int quantity) {
	this->goodsSoldPerTick = this->goodsSoldPerTick + quantity;
	return 1;
}
