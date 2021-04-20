#include "Creature.h"
#include "Diary.h"
//#define DEBUG

Creature::Creature(string name)
{
	Creature::name = name;
	start_day = Diary::day;
}

Creature::Creature(string name, Creature in)
{
	Creature::name = name;
	start_day = Diary::day;
	myPart.assign(in.myPart.begin(), in.myPart.end());

	for (size_t i = 0; i < in.mylog.size(); i++)
	{
		in.mylog[i].copy = 1;
	}
	mylog.assign(in.mylog.begin(), in.mylog.end());
}

void Creature::operator=(int in)
{

	Diary tmp;
	tmp.day_stamp = Diary::day;
	tmp.original_value = myPart[changeIndex].value;
	tmp.changed_value = in;
	tmp.body_part = myPart[changeIndex].body_part;

	myPart[changeIndex].value = in;

	mylog.push_back(tmp);
}

void Creature::operator+=(int in)
{
	if (in != 0)
	{
		Diary tmp;
		tmp.day_stamp = Diary::day;
		tmp.original_value = myPart[changeIndex].value;
		tmp.changed_value = myPart[changeIndex].value + in;
		tmp.body_part = myPart[changeIndex].body_part;

		myPart[changeIndex].value += in;
		mylog.push_back(tmp);
	}
	
}

void Creature::operator-=(int in)
{
	if (in != 0)
	{
		Diary tmp;
		tmp.day_stamp = Diary::day;
		tmp.original_value = myPart[changeIndex].value;
		tmp.changed_value = myPart[changeIndex].value - in;
		tmp.body_part = myPart[changeIndex].body_part;

		myPart[changeIndex].value -= in;
		mylog.push_back(tmp);
	}
}

void Creature::PrintStatus()
{
	cout << Creature::name << "'s status:" << endl;
	for (size_t i = 0; i < myPart.size(); i++)
	{
		if (myPart[i].value > 0)
		{
			cout << myPart[i].body_part << " * " << myPart[i].value << endl;
		}
	}
	cout << endl;
}

void Creature::PrintLog()
{
	cout << name << "'s log:" << endl;
	int start_index = 0;
	for (size_t i = 0; i < Diary::day_record.size(); i++)
	{
		if (Diary::day_record[i] == start_day)
		{
			start_index = i;
		}
	}

	string order[3] = { "appeared", "increased", "decreased" };

	for (size_t i = start_index; i < Diary::day_record.size(); i++)
	{
		int print_once = 0;
		for (size_t j = 0; j < mylog.size(); j++)
		{
			if (!print_once)
			{
				cout << "Day " << Diary::day_record[i] << endl;
				print_once = 1;
			}

			if (Diary::day_record[i] == mylog[j].day_stamp && mylog[j].copy != 1)
			{
				int judge_result = 3;
				if (mylog[j].changed_value > mylog[j].original_value && mylog[j].original_value == 0)
				{
					judge_result = 0;
				}
				else if (mylog[j].changed_value > mylog[j].original_value && mylog[j].original_value != 0)
				{
					judge_result = 1;
				}
				else if (mylog[j].changed_value < mylog[j].original_value && mylog[j].original_value != 0)
				{
					judge_result = 2;
				}
				if (judge_result != 3)
				{
					string log_message = name + "'s " + mylog[j].body_part + " " +
						order[judge_result] + " (" + to_string(mylog[j].original_value) + " -> " + to_string(mylog[j].changed_value) + ")";
					cout << log_message << "." << endl;	
				}
				
			}
		}
	}
	cout << endl;
}

//obtain
/*
	Obtain the specified body part of Creature. (Overload operator [])
	For example: c["leg"]: return to the body part of Creature c named "leg".
*/

Creature& Creature::operator[](string in)
{
	for (size_t i = 0; i < myPart.size(); i++)
	{
		if (myPart[i].body_part == in)
		{
			changeIndex = i;
			return *this;
		}
	}

	Body_Part tmp_BDP = { in, 0 };
	myPart.push_back(tmp_BDP);
	changeIndex = myPart.size() - 1;
	return *this;
}
