#include <iostream>
#include "Pop.h"
#include "Market.h"

int main() {
	Pop* cool = new Pop(12.00, 0, "farmer", "1");
	Pop * cool2 = new Pop(12.00, 0, "rancher", "2");
	Market* market = new Market();
	market->addPop(cool);
	market->addPop(cool2);
	int i = 0;
	while (i < 10) {
	cool->Tick();
	cool2->Tick();
	cool->printPopInfo();
	cool2->printPopInfo();
	i++;
}
	return 0;
}