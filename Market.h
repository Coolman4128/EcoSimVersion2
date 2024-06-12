#include <list>
#include <string>

class Pop;
class Order;

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
	private:
		std::list<Pop*> Pops;
		std::list<Order*> Orders;
		int popCount;


};