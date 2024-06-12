#include <string>

class Pop;

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