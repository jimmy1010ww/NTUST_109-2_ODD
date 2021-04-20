#include "Diary.h"
#include "Creature.h"

int main() {

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("41165");
	Creature unknownB("UB", unknownA);
	unknownB["wing"] += 4;
	Creature unknownC("UC", unknownB);
	unknownC["leg"] += 26;
	unknownC.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA.PrintStatus();
	unknownA.PrintLog();

}

