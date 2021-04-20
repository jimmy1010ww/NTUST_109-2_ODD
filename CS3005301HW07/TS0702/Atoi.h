#include <string>
#include <cmath>
using namespace std;

class Atoi {

private:
	bool negative;
	string beTrans;
	
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();

};    