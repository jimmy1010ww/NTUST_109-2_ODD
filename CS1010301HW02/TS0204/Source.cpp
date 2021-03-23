#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define DEBUG

using namespace std;

int main() {

	int n;

	cin >> n;

	while (!cin.eof())
	{
		string Name_tmp, Salary_tmp, Bouns_tmp;

		int Name_LEN = 0
			,Salary_LEN = 0
			,Bouns_LEN = 0;

		vector<string> Name, Salary, Bouns;

		for (size_t i = 0; i < n; i++)
		{
			cin >> Name_tmp >> Salary_tmp >> Bouns_tmp;

			Name.push_back(Name_tmp);
			Salary.push_back(Salary_tmp);
			Bouns.push_back(Bouns_tmp);


			if (Name_tmp.length() > Name_LEN)
			{
				Name_LEN = Name_tmp.length();
			}
			if (Salary_tmp.length() > Salary_LEN)
			{
				Salary_LEN = Salary_tmp.length();
			}
			if (Bouns_tmp.length() > Bouns_LEN)
			{
				Bouns_LEN = Bouns_tmp.length();
			}
		}
		
		for (size_t i = 0; i < n; i++)
		{
			cout << setw(Name_LEN)   << Name[i]   << "|  "
				 << setw(Salary_LEN) << Salary[i] << "|  "
				 << setw(Bouns_LEN)  << Bouns[i] << endl;
		}
		
		cin >> n;
	}

	

}