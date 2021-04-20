#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
	string input1,input2;
	while (getline(cin,input1))
	{
		getline(cin, input2);
		int str_1 = input1.size() + 1;
		int str_2 = input2.size() + 1;
		vector <vector<int>> slove(str_1,vector<int> (str_2));

		for (int i = 0; i < str_1; i++)
		{
			slove[i][0] = i;
		}
		for (int i = 0; i < str_2; i++)
		{
			slove[0][i] = i;
		}


		for (int i = 1; i <= input1.size(); i++) {
			for (int j = 1; j <= input2.size(); j++) {
				if (input1[i-1] != input2[j - 1])
				{
					slove[i][j] = min(min(slove[i - 1][j] + 1, slove[i][j - 1] + 1), slove[i - 1][j-1]+1);
				}
				else
				{
					slove[i][j] = min(min(slove[i - 1][j] + 1, slove[i][j - 1] + 1), slove[i - 1][j - 1]);
				}
				
			}
		}

		cout << slove[slove.size() - 1][slove[0].size() - 1] << endl;
	}

}