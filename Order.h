#include <string>

class Pop;

//This class defines an order which is a request to sell a good at a certain price and quantity.

class Order {
	public:
		Order(double price, std::string good, int quantity, Pop* seller);
		int fillOrder(Pop* buyer, int quantity);
		double getPrice();
		std::string getGood();
		int getQuantity();
		Pop* getSeller();
		void returnOrder();
	private:
		double price;
		std::string good;
		int quantity;
		Pop* seller;
};