#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

int Collatz(ll input);

int main() {
	ll i, j, count = 1, max_count = 1;
	cin >> i >> j;
	
	
	while (!cin.eof())
	{
		cout << i << " " << j << " ";
		if (i > j)
		{
			swap(i, j);
		}
		for (ll k = i; k <= j; k++)
		{
			count = Collatz(k);
			if (max_count < count)
			{
				max_count = count;
			}
		}
		cout << max_count << endl;
		count = 1;
		max_count = 1;
		cin >> i >> j;
	}
}

int Collatz(ll input) {
	ll count = 1;
	while (input != 1)
	{
		if (input % 2 == 0)
		{
			input /= 2;
			count++;
		}
		else
		{
			input = input * 3 + 1;
			count++;
		}		
	}
	return 	count;
	
}