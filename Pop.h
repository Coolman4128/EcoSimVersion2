#include <string>
#include <map>


class Pop {
	public: 
		Pop(double money, int happiness, std::string job, std::string ID);
		int getHappiness();
		double getMoney();
		int getNeedsWithGood(std::string);
		int getGoodAmount(std::string);
		void Tick();
		void printPopInfo();
	private:
		std::string ID;
		std::string job;
		int resetNeeds();
		int supplyNeeds();
		int calculateHappiness();
		int endTick();
		int work();
		double money;
		std::map<std::string, int> needs;
		std::map<std::string, int> goods;
		int happiness;




};

