#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

int main() {
	double r, ans; //雙精度浮點數
	const double PI = 3.14159265358979323846;	//宣告PI為常數
	cin >> r;
	while (!cin.eof())
	{
		ans = ((4.0 / 3.0) * PI * pow(r,3));	// 4/3 也要是double
		cout << fixed <<setprecision(6) << ans << endl;
		cin >> r;
	}
}