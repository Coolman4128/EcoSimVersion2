#include <iostream>
#include "Pop.h"
#include "Market.h"

int main() {
	Market* market = new Market();
	market->createPop(100, 1, "farmer");
	market->createPop(100, 1, "rancher");
	int i = 0;
	while (i < 10) {
		market->TickPops();
	i++;
}
	return 0;
}