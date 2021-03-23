#include "HotDogStand.h"

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand(const char * id)
{
	HotDogStand::hotDogSellAmount = 0;
	HotDogStand::standId = (char*)id;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	HotDogStand::hotDogSellAmount = amount;
	HotDogStand::totalSellAmount += amount;
	HotDogStand::standId = (char*)id;
}

void HotDogStand::justSold()
{
	HotDogStand::hotDogSellAmount++;
	HotDogStand::totalSellAmount++;
}

void HotDogStand::print()
{
	cout << HotDogStand::standId << " " << HotDogStand::hotDogSellAmount << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return HotDogStand::hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return HotDogStand::totalSellAmount;
}
