#include <iostream>
#include <iomanip>
#include <cmath>

typedef unsigned long long int ullt;
using namespace std;

ullt GCD(ullt a, ullt b);

int main() {
	ullt num_1, num_2;

	cin >> num_1 >> num_2;
	while (!cin.eof())
	{
		cout << GCD(num_1, num_2) <<endl;
		cin >> num_1 >> num_2;
	}

}

ullt GCD(ullt a, ullt b) {
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return GCD(b, a % b);
	}
}
