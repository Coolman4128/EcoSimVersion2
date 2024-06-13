#include <string>
#include <map>

// This class will hold the market data for what goods are at what prices, and how many goods are moving each tick. 

class Market;

class MarketData {


public:
	MarketData(Market* market);
	double getPriceAverage();
	int getTransactionsPerTick();
	int getGoodsSoldPerTick();
	double updatePriceAverage(double price);
	int clearTickData();
	int addTransaction();
	int addGoodsSold(int quantity);

private:
	double priceAverage;
	int transactionsPerTick;
	int goodsSoldPerTick;
	Market* market;
	std::map<std::string, int> 

};
