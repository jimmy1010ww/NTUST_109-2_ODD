//#define DEBUG
#include "NumberGame.h"

void NumberGame::LoadNumberList()
{
	fstream fin;
	fin.open(FileInName, ios::in);

	int tmp;
	while (fin >> tmp)
	{
		s.push_back(tmp);
	}
	fin.close();
}

void NumberGame::PrintAllValid()
{
	//init input number list
	vector<int> input_number;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] - '0' != 0)
		{
			int tmp = input[i] - '0';
			input_number.push_back(tmp);
		}
	}

	//sort increase
	sort(input_number.begin(), input_number.end(), greater<int>());

	int biggest_number = 1;
	for (size_t i = 0; i < input_number.size(); i++)
	{
		biggest_number *= input_number[i];
	}

	int index_s = 0; //s index_s
	while (index_s < s.size())
	{
		if (s[index_s] > biggest_number)
		{
			break;
		}
		else
		{
			if (s[index_s] == 1)
			{
				for (size_t i = 0; i < input_number.size(); i++)
				{
					if ( input_number[i] == s[index_s])
					{
						cout << s[index_s] << endl;
						valid.push_back(s[index_s]);
						break;
					}
				}
				index_s++;
			}
			else
			{
				int element_order = 0;
				while (element_order < input_number.size())
				{
					int tmp = s[index_s];
					for (int i = element_order; i < input_number.size(); i++)
					{
						if (tmp % input_number[i] == 0)
						{
							tmp /= input_number[i];
							if (tmp == 1)
							{
								cout << s[index_s] << endl;
								valid.push_back(s[index_s]);
								break;
							}
						}
					}
					if (tmp == 1)
					{
						break;
					}
					element_order++;
				}
				index_s++;
			}
		}
	}
}

void NumberGame::Reset()
{
	s.clear();
	valid.clear();
}

