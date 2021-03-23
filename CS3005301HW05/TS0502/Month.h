#ifndef Month_H
#define Month_H
#define MONTH_LEN 12		//one year have 12 months
#define MONTH_ABBREVIATION_LEN 3		//abbreviation month lenth
#include <iostream>
#include <string>

using namespace std;

class Month
{
public:
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);

	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	Month nextMonth();
private:
	int month;
};

#endif // !Month_H
