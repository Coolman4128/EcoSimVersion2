#include <string>
#include <map>

//This class defines a pop which is a member of the population in the simulation. 

class Market;

class Pop {
	public: 
		Pop(double money, int happiness, std::string job, std::string ID, Market* market);
		int getHappiness();
		double getMoney();
		int getNeedsWithGood(std::string);
		int getGoodAmount(std::string);
		void Tick();
		void printPopInfo();
		double pay(double amount);
		double spend(double amount);
		int giveGood(std::string good, int quantity);
		Market* getMarket();
	private:
		static const int NEEDS; //How much each pop needs of each good per tick
		static const std::string GOODS[]; //The goods that each pop can have
		Market* market;
		std::string ID;
		std::string job;
		int resetNeeds();
		int submitOrder(std::string good, double price, int quantity);
		int supplyNeeds();
		int calculateHappiness();
		int buyDecision();
		int sellDecision();
		int endTick();
		int work();
		double money;
		std::map<std::string, int> needs;
		std::map<std::string, int> goods;
		int happiness;
};