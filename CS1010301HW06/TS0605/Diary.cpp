#include "Diary.h"
#include "Creature.h"

string Diary::day;
vector<string> Diary::day_record;

void Diary::NewDay(string day)
{
	Diary::day = day;
	day_record.push_back(day);
}
