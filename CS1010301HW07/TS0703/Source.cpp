#include <iostream>
#include <iomanip>
#include <string>

#define ROW 3
#define COL 3

using namespace std;

char ONE[ROW][COL] = {  {' ',' ',' '},
						{' ',' ','|'},
						{' ',' ','|'} };

char TWO[ROW][COL] = {  {' ','_',' '},
						{' ','_','|'},
						{'|','_',' '} };

char THREE[ROW][COL] = {{' ','_',' '},
						{' ','_','|'},
						{' ','_','|'} };

char FOUR[ROW][COL] = { {' ',' ',' '},
						{'|','_','|'},
						{' ',' ','|'} };

char FIVE[ROW][COL] = { {' ','_',' '},
						{'|','_',' '},
						{' ','_','|'} };

char SIX[ROW][COL] = {  {' ','_',' '},
						{'|','_',' '},
						{'|','_','|'} };

char SEVEN[ROW][COL] = {{' ','_',' '},
						{' ',' ','|'},
						{' ',' ','|'} };

char EIGHT[ROW][COL] = {{' ','_',' '},
						{'|','_','|'},
						{'|','_','|'} };

char NINE[ROW][COL] = { {' ','_',' '},
						{'|','_','|'},
						{' ','_','|'} };

char ZERO[ROW][COL] = { {' ','_',' '},
						{'|',' ','|'},
						{'|','_','|'} };

void PrintNum(int print_number,int i);
int main()
{
	string input;
	while (getline(cin, input))
	{
		for (size_t k = 0; k < input.size(); k++)
		{
			if (isdigit(input[k]))
			{
				PrintNum(input[k] - '0', 0);
			}
		}
		cout << endl;
		for (size_t k = 0; k < input.size(); k++)
		{
			if (isdigit(input[k]))
			{
				PrintNum(input[k] - '0', 1);
			}
		}
		cout << endl;
		for (size_t k = 0; k < input.size(); k++)
		{
			if (isdigit(input[k]))
			{
				PrintNum(input[k] - '0', 2);
			}
		}
		cout << endl;
	}
}


void PrintNum(int print_number, int i)
{
	switch (print_number)
	{
	case 1:
		for (size_t j = 0; j < COL; j++)
		{
			cout << ONE[i][j];
		}
		break;
	case 2:
		for (size_t j = 0; j < COL; j++)
		{
			cout << TWO[i][j];
		}
		break;
	case 3:
		for (size_t j = 0; j < COL; j++)
		{
			cout << THREE[i][j];
		}
		break;
	case 4:
		for (size_t j = 0; j < COL; j++)
		{
			cout << FOUR[i][j];
		}
		break;
	case 5:
		for (size_t j = 0; j < COL; j++)
		{
			cout << FIVE[i][j];
		}
		break;
	case 6:
		for (size_t j = 0; j < COL; j++)
		{
			cout << SIX[i][j];
		}
		break;
	case 7:
		for (size_t j = 0; j < COL; j++)
		{
			cout << SEVEN[i][j];
		}
		break;
	case 8:
		for (size_t j = 0; j < COL; j++)
		{
			cout << EIGHT[i][j];
		}
		break;
	case 9:
		for (size_t j = 0; j < COL; j++)
		{
			cout << NINE[i][j];
		}
		break;
	case 0:
		for (size_t j = 0; j < COL; j++)
		{
			cout << ZERO[i][j];
		}
		break;
	default:
		break;
	}
}

