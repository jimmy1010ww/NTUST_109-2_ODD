#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define DEBUG

using namespace std;

/*
Not over $750   1 % of income

$750¡X$2, 250    $7.50 plus 2 % of amount over $750

$2, 250¡X$3, 750  $37.50 plus 3 % of amount over $2, 250

$3, 750¡X$5, 250    $82.50 plus 4 % of amount over $3, 750

$5, 250¡X$7, 000  $142.50 plus 5 % of amount over $5, 250

Over $7, 000        $230.00 plus 6 % of amount over $7, 000

*/

int main() {

	long long int income;
	double tax_payable;

	cin >> income;

	while (!cin.eof())
	{
		if (income < 750)
		{
			tax_payable = income * 0.01;
		}
		else if (income < 2250)
		{
			tax_payable = (income - 750) * 0.02 + 7.50;
		}
		else if (income < 3750)
		{
			tax_payable = (income - 2250) * 0.03 + 37.50;
		}
		else if (income < 5250)
		{
			tax_payable = (income - 3750) * 0.04 + 82.50;
		}
		else if (income < 7000)
		{
			tax_payable = (income - 5250) * 0.05 + 142.50;
		}
		else if (income >= 7000)
		{
			tax_payable = (income - 7000) * 0.06 + 230.00;
		}

		cout << fixed << setprecision(2) << tax_payable << endl;

		cin >> income;
	}
	
}

