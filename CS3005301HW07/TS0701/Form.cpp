#include "Form.h"
//#define DEBUG

void Form::ProcessInputWord()
{
	for (size_t i = 0; i < myWord.origin_word.size(); i++)
	{
		if (isalpha(myWord.origin_word[i]))
		{
			if (myWord.origin_word[i] > 90)	//lower
			{
				myWord.lower += myWord.origin_word[i];
				myWord.upper += toupper(myWord.origin_word[i]);
			}
			else  //uppper
			{
				myWord.lower += tolower(myWord.origin_word[i]);
				myWord.upper += myWord.origin_word[i];
			}
		}
	}


	for (size_t i = 0; i < myWord.lower.size(); i++)
	{
		myWord.count[myWord.lower[i] - 97]++;
	}

#ifdef DEBUG
	cout << "myWord.origin_word : ";
	for (size_t i = 0; i < myWord.origin_word.size(); i++)
	{
		cout << myWord.origin_word[i];
	}
	cout << endl;
	cout << "myWord.upper : ";
	for (size_t i = 0; i < myWord.origin_word.size(); i++)
	{
		cout << myWord.upper[i];
	}
	cout << endl;
	cout << "myWord.lower : ";
	for (size_t i = 0; i < myWord.origin_word.size(); i++)
	{
		cout << myWord.lower[i];
	}
	cout << endl;
	cout << "myWord.count : " << endl;
	for (size_t i = 0; i < 26; i++)
	{
		if (myWord.count[i] > 0)
		{
			cout << (char)(i + 97) << " : " << myWord.count[i] << endl;
		}
	}
#endif 

}

void Form::Load_CompareWord()
{
	vector <string> data_word;
	fstream fin;
	fin.open(FileName, ios::in);
	string tmp;
	while (fin >> tmp)
	{
		if (tmp[0] < 90)
		{
			tmp[0] = tolower(tmp[0]);
		}
		if (myWord.count[tmp[0] - 97] > 0)
		{
			data_word.push_back(tmp);
			int data_count[26] = { 0 };
			for (size_t i = 0; i < tmp.size(); i++)
			{
				if (tmp[i] < 90)
				{
					tmp[i] = tolower(tmp[i]);
				}
				data_count[tmp[i] - 97]++;
			}



			int valid_flag = 1;
			for (size_t i = 0; i < 26; i++)
			{
				if (data_count[i] > 0)
				{
					if (myWord.count[i] < data_count[i])
					{
						valid_flag = 0;
						break;
					}
				}
			}

			if (valid_flag)
			{
				cout << tmp << endl;
			}
		}

	}
}

void Form::PrintFoundWords()
{
}
