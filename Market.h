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
	private:
		std::list<Pop*> Pops;
		std::list<Order*> Orders;
		int popCount;


};