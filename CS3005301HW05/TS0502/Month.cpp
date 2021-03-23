#include "Month.h"

const string MONTH_NAME[MONTH_LEN] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

Month::Month()
{
	Month::month = 1;
}

Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n')
		Month::month = 1;
	else if (first == 'F' && second == 'e' && third == 'b')
		Month::month = 2;
	else if (first == 'M' && second == 'a' && third == 'r')
		Month::month = 3;
	else if (first == 'A' && second == 'p' && third == 'r')
		Month::month = 4;
	else if (first == 'M' && second == 'a' && third == 'y')
		Month::month = 5;
	else if (first == 'J' && second == 'u' && third == 'n')
		Month::month = 6;
	else if (first == 'J' && second == 'u' && third == 'l')
		Month::month = 7;
	else if (first == 'A' && second == 'u' && third == 'g')
		Month::month = 8;
	else if (first == 'S' && second == 'e' && third == 'p')
		Month::month = 9;
	else if (first == 'O' && second == 'c' && third == 't')
		Month::month = 10;
	else if (first == 'N' && second == 'o' && third == 'v')
		Month::month = 11;
	else if (first == 'D' && second == 'e' && third == 'c')
		Month::month = 12;
	else
		Month::month = 1;
}

Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12)
	{
		Month::month = 1;
	}
	else
	{
		Month::month = monthInt;
	}
	
}

void Month::inputInt()
{
	int x = 0;
	cin >> x;
	if (x < 1 || x > 12)
	{
		Month::month = 1;
	}
	else
	{
		Month::month = x;
	}
}

void Month::inputStr()
{
	char inputMonth[MONTH_ABBREVIATION_LEN];
	for (size_t i = 0; i < MONTH_ABBREVIATION_LEN; i++)
	{
		cin >> inputMonth[i];
	}

	int count = 0;
	for (size_t i = 0; i < MONTH_LEN; i++)
	{
		for (size_t j = 0; j < MONTH_ABBREVIATION_LEN; j++)
		{

			if (inputMonth[j] == MONTH_NAME[i][j])
			{
				count++;
			}
		}
		if (count == 3)
		{
			Month::month = ((i == 0) ? 1 : i + 1);
		}
		count = 0;
	}
	
}

void Month::outputInt()
{
	cout << Month::month;
}

void Month::outputStr()
{
	cout << MONTH_NAME[(Month::month - 1) == 0 ? 0 : (Month::month - 1)];

}

Month Month::nextMonth()
{
	int nextmonth = Month::month + 1;
	if (Month::month + 1 == 13)
	{
		return Month(1);
	}
	else
	{
		return Month(nextmonth);
	}
}
