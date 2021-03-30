#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

#define RECORD_MAX_NUM 10
#define FIRSTNAME_MAX_LEN 25
#define LASTNAME_MAX_LEN 30
#define PHONE_MAX_LEN 15

using namespace std;

typedef struct {
	char firstName[FIRSTNAME_MAX_LEN];
	char lastName[LASTNAME_MAX_LEN];
	char phone[PHONE_MAX_LEN];
	string command;
} StRec;

void Print(StRec student[]);
int Insert(StRec student[]);
int Search(StRec student[], string input[]);	//mode 0 skip input ; 1 get input
int Delete(StRec student[]);
int Check_Format(string input[]);
int current_order = 0;

int main() {
	StRec myStudent[RECORD_MAX_NUM] = { 0 };
	string command;

	/*
	string cheat;
	cin >> cheat;
	while (!cin.eof())
	{
		cout << cheat << " |";
		cin >> cheat;
	}
	*/
	
	while (cin >> command)
	{
		if (current_order < RECORD_MAX_NUM)
		{
			if (command == "insert")
			{
				int result = Insert(myStudent);
				if (result == -1)
				{
					cout << "Insert Error" << endl;
				}
				else if (result == -2)
				{
					cout << "Input Error" << endl;
				}

			}
			else if (command == "delete")
			{
				int result = Delete(myStudent);
				if (result == -1)
				{
					cout << "Delete Error" << endl;
				}
				else if (result == -2)
				{
					cout << "Input Error" << endl;
				}

			}
			else if (command == "search")
			{
				string input[3];
				cin >> input[0] >> input[1] >> input[2];
				int result = Search(myStudent, input);
				if (result >= 0)
				{
					cout << result << endl;
				}
				else if (result == -1)
				{
					cout << "Search Error" << endl;
				}
				else if (result == -2)
				{
					cout << "Input Error" << endl;
				}
			}
			else if (command == "print")
			{
				Print(myStudent);
			}
			else
			{
				cout << "Input Error" << endl;
			}

		}
		else
		{
			if (command == "insert")
			{
				string input[3];
				cin >> input[0] >> input[1] >> input[2];
				cout << "Insert Error" << endl;
			}
			else if (command == "delete")
			{
				int result = Delete(myStudent);
				if (result == -1)
				{
					cout << "Delete Error" << endl;
				}
				else if (result == -2)
				{
					cout << "Input Error" << endl;
				}
			}
			else if (command == "search")
			{
				string input[3];
				cin >> input[0] >> input[1] >> input[2];
				int result = Search(myStudent, input);
				if (result >= 0)
				{
					cout << result << endl;
				}
				else if (result == -1)
				{
					cout << "Search Error" << endl;
				}
				else if (result == -2)
				{
					cout << "Input Error" << endl;
				}
			}
			else if (command == "print")
			{
				Print(myStudent);
			}
			else
			{
				cout << "Input Error" << endl;
			}
		}

	}

}

int Check_Format(string input[]) {
	if (input[0].length() <= FIRSTNAME_MAX_LEN &&
		input[1].length() <= LASTNAME_MAX_LEN &&
		input[2].length() <= PHONE_MAX_LEN)
	{
		if (atoll(input[2].c_str()) == 0)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void Print(StRec student[]) {
	if (current_order == 0)
	{
		cout << "Print Error" << endl;
	}
	else
	{
		for (int i = 0; i < current_order; i++)
		{
			if (student[i].firstName[0] != NULL)
			{
				cout << student[i].firstName << " "
					<< student[i].lastName << " "
					<< student[i].phone << endl;
			}
			else
			{
				cout << "Print Error" << endl;
			}
		}
	}


}

int Insert(StRec student[])
{
	string input[3];
	cin >> input[0] >> input[1] >> input[2];
	if (Check_Format(input) == 1)
	{
		int result = Search(student, input);
		if (result == -1)
		{
			strcpy_s(student[current_order].firstName, input[0].c_str());
			strcpy_s(student[current_order].lastName, input[1].c_str());
			strcpy_s(student[current_order].phone, input[2].c_str());
			current_order++;
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -2;
	}
}

int Search(StRec student[], string input[])
{

	if (Check_Format(input) == 1)
	{
		for (int i = 0; i < current_order; i++)
		{
			if (input[0] == student[i].firstName && input[1] == student[i].lastName &&input[2] == student[i].phone)
			{
				return i;	//success
			}
		}
		return -1;	
	}
	else
	{
		return -2;
	}
}

int Delete(StRec student[])
{
	string input[3];
	cin >> input[0] >> input[1] >> input[2];
	if (Check_Format(input) == 1)
	{
		int result = Search(student, input);
		if (result != -1)
		{
			int last = 0;
			for (int j = result; j < current_order-1; j++)
			{
				swap(student[j], student[j + 1]);
				last = j;
			}
			memset(&student[last + 1].firstName[0], 0, sizeof(student[result].firstName));
			memset(&student[last + 1].lastName[0], 0, sizeof(student[result].lastName));
			memset(&student[last + 1].phone[0], 0, sizeof(student[result].phone));
			current_order--;
			return 1;	//success
		}
		else
		{
			return -1;	//does not exist
		}
	}
	else
	{
		return -2;	//Input Error
	}
	
}

