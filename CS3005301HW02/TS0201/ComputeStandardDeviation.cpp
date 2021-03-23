#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <assert.h>

#define NDEBUG //除錯顯示

using namespace std;

int main() {

	int n;
	double  Deviation,		//偏差
			Average,		
			Variance = 0,	//變異數
			Sum = 0;

	cin >> n;

	while (!cin.eof())
	{
		//宣告vector 陣列
		vector<double> s(n);	//儲存第一次的和
		vector<double> d(n);	//儲存每一個變異數的數值
		for (size_t i = 0; i < n; i++)
		{
			cin >> s[i];
			Sum += s[i];
		}

		Average = (double)Sum / (double)n;	//取平均

#ifndef NDEBUG
		cout << "------------------------" << endl;
		cout << "Input Data :";
		for (size_t i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
		cout << "n : " << n << endl;
		cout << "Sum : " << Sum << endl;
		cout << "Average : " << Average << endl;
		cout << "------------------------" << endl;
#endif // !NDEBUG

		/*計算變異數*/
		for (size_t i = 0; i < n; i++)
		{
			d[i] = pow(s[i] - Average, 2);	
		}

		for (size_t i = 0; i < n; i++)
		{
			Variance += d[i];
		}

		Variance /= n;
		Deviation = sqrt(Variance);

		/*輸出*/
		cout << setprecision(6) << "Average:" << Average << '\t';
		cout << setprecision(6)
			 << "Standard deviation:" << Deviation << endl;
		cout.unsetf(ios::fixed);

		
		cin >> n;	//下一筆資料

		//init var
		Sum = 0;
		Variance = 0;
	}

	return 0;
}