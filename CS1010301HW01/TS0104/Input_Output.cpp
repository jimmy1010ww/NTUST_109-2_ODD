#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	string str;

	cin >> str;
	while (!cin.eof())
	{
		cout << setw(10) << str << endl;	//setw預設靠右
		cin >> str;
	}

}