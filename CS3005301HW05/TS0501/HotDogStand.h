#ifndef HotDogStand_H
#define HotDogStand_H
#include <iostream>
#include <string>
using namespace std;

class HotDogStand
{
public:
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

#endif