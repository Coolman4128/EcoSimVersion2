#include <list>
#include <string>

// This class defines a market, which is a group of pops that interact with each other using orders. 

class Pop;
class Order;
class MarketData;

class Market {
	public:
		Market();
		void addPop(Pop* pop);
		void createPop(double money, int happiness, std::string job);
		void addOrder(Order* order);
		void removePop(Pop* pop);
		void removeOrder(Order* order);
		Order* createOrder(double price, std::string good, int quantity, Pop* seller);
		void TickPops();
		MarketData* getMarketData();
	private:
		std::list<Pop*> Pops;
		std::list<Order*> Orders;
		int popCount;
		MarketData* marketData;


};