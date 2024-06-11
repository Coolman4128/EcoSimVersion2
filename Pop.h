#include <string>
#include <map>

class Pop {
	public: 
		Pop(double money, int happiness);
		int getHappiness();
		double getMoney();
		int getNeedsWithGood(std::string);
		int getGoodAmount(std::string);
	private:
		int supplyNeeds();
		int calculateHappiness();
		int startTick();
		int endTick();
		double money;
		std::map<std::string, int> needs;
		std::map<std::string, int> goods;
		int happiness;




};
