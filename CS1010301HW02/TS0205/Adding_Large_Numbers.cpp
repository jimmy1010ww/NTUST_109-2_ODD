#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define DIGITS 1
//s#define DEBUG

using namespace std;

struct BigInt
{
	string str;
	vector<int> num;
	int length = 0;
};

BigInt Add(const BigInt& lhs, const BigInt& rhs);

int main()
{
	int n;
	cin >> n;

	while (!cin.eof())
	{
		BigInt a, b;
		cin >> a.str;
		cin >> b.str;

		int a_check_flag = 1;
		int b_check_flag = 1;

		for (int i = 0; i < a.str.length(); i++)
		{
			if (!isdigit(a.str[i]))
			{
				a_check_flag = 0;
			}
		}
		for (int i = 0; i < b.str.length(); i++)
		{
			if (!isdigit(b.str[i]))
			{
				b_check_flag = 0;
			}
		}

		if (a_check_flag && b_check_flag)
		{
			for (int i = 0; i < a.str.length(); i++)
			{
				a.num.push_back(a.str[i] - '0');
			}
			for (int i = 0; i < b.str.length(); i++)
			{
				b.num.push_back(b.str[i] - '0');
			}

#ifdef DEBUG
			cout << "====================" << endl;
			cout << "a_length: " << a.str.length() << endl;
			cout << "b_length: " << b.str.length() << endl;
			cout << "a: ";
			for (int i = 0; i < a.str.length(); i++)
			{
				cout << a.num[i];
			}
			cout << endl;
			cout << "b: ";
			for (int i = 0; i < b.str.length(); i++)
			{
				cout << b.num[i];

			}
			cout << endl;
			cout << "====================" << endl;
#endif // DEBUG

			BigInt result = Add(a, b);
			//cout << "length : " << result.length << endl;
			for (int i = result.length - 1; i >= 0; i--)
			{
				cout << result.num[i];
			}
			cout << endl;
		}
		else
		{
			cout << "Not a valid number, please try again." << endl;
		}
	}
}

BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
	BigInt ans;
	int num_tmp = 0;
	int carry = 0;

	if (lhs.str.length() > rhs.str.length())
	{
		int samll_length = rhs.str.length()-1;
		for (int i = lhs.str.length() - 1; i >= 0; i--)
		{

			if (samll_length < 0)
			{
				num_tmp = lhs.num[i] + carry;
				carry = num_tmp / 10;
				num_tmp %= 10;
				ans.num.push_back(num_tmp);

			}
			else
			{
				num_tmp = lhs.num[i] + rhs.num[samll_length] + carry;
				carry = num_tmp / 10;
				num_tmp %= 10;
				ans.num.push_back(num_tmp);
			}

			samll_length--;
		}
		if (carry == 1)
		{
			ans.num.push_back(1);
		}
		ans.length = lhs.str.length() + carry;
	}
	else if (lhs.str.length() < rhs.str.length())
	{
		int samll_length = lhs.str.length() - 1;
		for (int i = rhs.str.length() - 1; i >= 0; i--)
		{
			if (samll_length < 0)
			{
				num_tmp = rhs.num[i] + carry;
				carry = num_tmp / 10;
				num_tmp %= 10;
				ans.num.push_back(num_tmp);

			}
			else
			{
				num_tmp = lhs.num[samll_length] + rhs.num[i] + carry;
				carry = num_tmp / 10;
				num_tmp %= 10;
				ans.num.push_back(num_tmp);
			}
			samll_length--;
		}
		if (carry == 1)
		{
			ans.num.push_back(1);
		}
		ans.length = rhs.str.length() + carry;
		
	}
	else
	{
		for (int i = rhs.str.length() - 1; i >= 0; i--)
		{
			num_tmp = lhs.num[i] + rhs.num[i] + carry;
			carry = num_tmp / (10 * DIGITS);
			num_tmp %= (10 * DIGITS);
			ans.num.push_back(num_tmp);

		}
		if (carry == 1)
		{
			ans.num.push_back(1);
		}
		ans.length = rhs.str.length() + carry;
	}

	

	return ans;
}

