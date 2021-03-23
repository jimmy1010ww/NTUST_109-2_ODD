#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//#define DEBUG

using namespace std;

int main() {


	string str;
	int str_len;
	cin >> str;
	str_len = str.length();
	int n = 0;

	while (!cin.eof())
	{
		while (pow(n, 2) < str_len)		//n^2 < 字元長度
		{
			n++;
		}

#ifdef DEBUG
		cout << "========================" << endl;
		cout << "str_len: " << str_len << endl;
		cout << "n: " << n << endl;
		cout << str << endl;
		cout << "========================" << endl;

#endif // 

		//宣告二維字元陣列
		vector<vector<char>> ans(n, vector<char>(n, '\0'));
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				//要小於超過陣列的長度
				if ((i * n + j) < str_len)
				{
					ans[i][j] = str[i * n + j];
				}
#ifdef DEBUG
				cout << "n: " << (i * n + j) << '\t';
				if ((i * n + j) < str_len)
				{
					cout << str[i * n + j] << endl;
				}
#endif //DEBUG
			}
		}

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				//null 的地方不輸出
				if (!ans[j][i] == '\0')
				{
					cout << ans[j][i];
				}
			}
			cout << endl;
		}

		//下一筆輸出
		cin >> str;
		str_len = str.length();
		n = 0;
	}
}