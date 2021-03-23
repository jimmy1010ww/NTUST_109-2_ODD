#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

//#define DEBUG

using namespace std;

int main() {

	vector<int> num;
	vector<vector<int>> count_num(2);
	int input_tmp;
	cin >> input_tmp;

	while (!cin.eof())
	{
		num.push_back(input_tmp);
		cin >> input_tmp;
	}

	sort(num.begin(), num.end());


#ifdef DEBUG
	cout << "======================" << endl;
	cout << "input : ";
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "num[0].size()" << num.size() << endl;
	cout << "======================" << endl;
#endif

	int last_num = 0;
	int cout_time = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (i == 0)
		{
			count_num[0].push_back(num[i]);
			count_num[1].push_back(count(num.begin(), num.end(), num[i]));
		}
		else if (num[i] != last_num)
		{
			count_num[0].push_back(num[i]);
			count_num[1].push_back(count(num.begin(), num.end(), num[i]));
		}
		last_num = num[i];
	}

	cout << "N" << '\t' << "count" << endl;
	last_num = count_num[0][0];
	for (int i = count_num[0].size() - 1; i >= 0; i--)
	{
		if (num[i] != last_num)
		{
			cout << count_num[0][i] << '\t' << count_num[1][i] << endl;
		}
		last_num = count_num[0][i];

	}
}