#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

#define DREW 0
#define BLANK 1
//#define CHEAT
//#define DEBUG	//DEBUG
int key = 1;
using namespace std;

struct background {
	vector<vector<int>> paper;
	int m = 0, n = 0;
	int w = 0, x = 0, y = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	string T_mode;
};


void paper_Init(background* myBackground);
void paper_Print(background myBackground);
void print_Square(background* myBackground);
void print_Triangle(background* myBackground);
void print_Line(background* myBackground);


int main() {
	background myBackground;
	int game_flag = 1;
	string mode;
	cin >> myBackground.m >> myBackground.n;

#ifdef CHEAT
	cout << "==" << myBackground.m << myBackground.n << "==";
#endif // CHEAT


	myBackground.paper.resize(myBackground.n, vector<int>(myBackground.m));
	paper_Init(&myBackground);
#ifdef DEBUG
	paper_Print(myBackground);
	cout << endl;
#endif // DEBUG

	while (game_flag)
	{
		cin >> mode;
		if (mode == "EXIT")
		{
			game_flag = 0;
			//break;
		}
		else
		{
#ifdef CHEAT
			cout << mode << "|";
#endif
			switch (mode[0])
			{
			case 'S':
				cin >> myBackground.w >> myBackground.x >> myBackground.y;
#ifdef CHEAT
				cout << "S: ";
				cout << myBackground.w << " " << myBackground.x << " " << myBackground.y << " |";
#endif
#ifndef CHEAT
				print_Square(&myBackground);
				if (key == 1)
				{
					paper_Print(myBackground);
				}
				else
				{
					key = 1;
					cout << endl;
				}
#endif
				break;

			case 'T':
				cin >> myBackground.w >> myBackground.x >> myBackground.y >> myBackground.T_mode;
#ifdef CHEAT
				cout << "T: ";
				cout << myBackground.w << " " << myBackground.x << " " << myBackground.y << myBackground.T_mode << " |";
#endif // CHEAT
#ifndef CHEAT
				print_Triangle(&myBackground);
				if (key == 1)
				{
					paper_Print(myBackground);
				}
				else
				{
					cout << endl;
					key = 1;
				}
#endif

				break;

			case 'L':
				cin >> myBackground.x1 >> myBackground.y1 >> myBackground.x2 >> myBackground.y2;
#ifdef CHEAT
				cout << "L: ";
				cout << myBackground.x1 << " " << myBackground.y1 << " " << myBackground.x2 << " " << myBackground.y2 << " |";
#endif
#ifndef CHEAT
				print_Line(&myBackground);
				if (key == 1)
				{
					paper_Print(myBackground);
				}
				else
				{
					cout << endl;
					key = 1;
				}
#endif

				break;

			default:
				break;
			}
		}
	}

}

void paper_Init(background* myBackground)
{
#ifdef DEBUG
	cout << "/* paper_Init */" << endl;
#endif //

	for (size_t i = 0; i < myBackground->n; i++)
	{
		for (size_t j = 0; j < myBackground->m; j++)
		{
			myBackground->paper[i][j] = BLANK;
		}
	}
}

void paper_Print(background myBackground)
{
#ifdef DEBUG
	cout << "/* paper_Print */" << endl;
#endif //
	for (size_t i = 0; i < myBackground.n; i++)
	{
		for (size_t j = 0; j < myBackground.m; j++)
		{
			if (myBackground.paper[i][j] == BLANK)
			{
				cout << "*";
			}
			else
			{
				cout << "X";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void print_Square(background* myBackground)
{
#ifdef DEBUG
	cout << "========================" << endl;
	cout << "/* print_Square */" << endl;
	cout << "myBackground.w : " << myBackground->w << endl;
	cout << "myBackground.x: " << myBackground->x << endl;
	cout << "myBackground.y : " << myBackground->y << endl;
	cout << "========================" << endl;
#endif

	if ((myBackground->w + myBackground->x) > myBackground->m ||
		myBackground->n < (myBackground->w + myBackground->y - 1))
	{
		cout << "Out of range." << endl;
		key = 0;
	}
	else
	{
		int x, y;
		for (int i = myBackground->y; i < (myBackground->y + myBackground->w); i++)
		{
			for (int j = myBackground->x; j < myBackground->x + myBackground->w; j++)
			{
				myBackground->paper[i][j] = DREW;
			}
		}
	}

}

void print_Triangle(background* myBackground)
{
#ifdef DEBUG
	cout << endl;
	cout << "========================" << endl;
	cout << "/* print_Triangle */" << endl;
	cout << "myBackground.w : " << myBackground->w << endl;
	cout << "myBackground.x: " << myBackground->x << endl;
	cout << "myBackground.y : " << myBackground->y << endl;
	cout << "myBackground.T_mode : " << myBackground->T_mode << endl;
	cout << "========================" << endl;
#endif //1
	if (myBackground->T_mode[0] == 'R')	//R
	{
		if (myBackground->T_mode[1] == 'U')		//RU
		{
#ifdef DEBUG
			cout << "/* RIGHT UP */" << endl;
#endif
			if ((myBackground->y - myBackground->w + 1 < 0) || (myBackground->x + myBackground->w - 1 > myBackground->m))
			{
				cout << "Out of range." << endl;
				key = 0;
			}
			else
			{
				for (int i = myBackground->y; i > myBackground->y - myBackground->w; i--)
				{
					for (int j = myBackground->x; j < myBackground->x + myBackground->w - (myBackground->y - i); j++)
					{
						myBackground->paper[i][j] = DREW;
					}
				}
			}

		}
		else	//RD
		{
#ifdef DEBUG
			cout << "/* RIGHT DOWN */" << endl;
#endif
			if ((myBackground->y + myBackground->w - 1 > myBackground->n) || (myBackground->x + myBackground->w - 1 > myBackground->m))
			{
				cout << "Out of range." << endl;
				key = 0;
			}
			else
			{
				for (int i = myBackground->y; i < myBackground->y + myBackground->w; i++)
				{
					for (int j = myBackground->x; j < myBackground->x + myBackground->w - (i - myBackground->y); j++)
					{
						myBackground->paper[i][j] = DREW;
					}
				}
			}
		}
	}
	else if (myBackground->T_mode[0] == 'L')
	{
		if (myBackground->T_mode[1] == 'U')	//LU
		{
#ifdef DEBUG
			cout << "/* LEFT UP */" << endl;
#endif
			if ((myBackground->y - myBackground->w + 1 < 0) || (myBackground->x - myBackground->w + 1 < 0))

			{
				cout << "Out of range." << endl;
				key = 0;
			}
			else
			{
				for (int i = myBackground->y; i > myBackground->y - myBackground->w; i--)
				{
					for (int j = myBackground->x; j > myBackground->x - myBackground->w + (myBackground->y - i); j--)
					{
						myBackground->paper[i][j] = DREW;
					}
				}
			}
		}
		else {	//LD
#ifdef DEBUG
			cout << "/* LEFT DOWN */" << endl;
#endif
			if ((myBackground->y + myBackground->w - 1 > myBackground->n) || (myBackground->x - myBackground->w + 1 < 0))
			{
				cout << "Out of range." << endl;
				key = 0;
			}
			else
			{
				for (int i = myBackground->y; i < myBackground->y + myBackground->w; i++)
				{
					for (int j = myBackground->x; j > myBackground->x - myBackground->w + (i - myBackground->y); j--)
					{
						myBackground->paper[i][j] = DREW;
					}
				}
			}
		}
	}
}

void print_Line(background* myBackground)
{
#ifdef DEBUG
	cout << endl;
	cout << "========================" << endl;
	cout << "/* print_Line */" << endl;
	cout << "myBackground.x1: " << myBackground->x1 << endl;
	cout << "myBackground.x2: " << myBackground->x2 << endl;
	cout << "myBackground.y1 : " << myBackground->y1 << endl;
	cout << "myBackground.y2 : " << myBackground->y2 << endl;
	cout << "========================" << endl;
#endif

	if (myBackground->x1 >= myBackground->m ||
		myBackground->x2 >= myBackground->m ||
		myBackground->y1 >= myBackground->n ||
		myBackground->y2 >= myBackground->n)
	{
		cout << "Out of range." << endl;
		key = 0;
	}
	else {
		if (myBackground->y1 == myBackground->y2)
		{
			int length = abs(myBackground->x1 - myBackground->x2);
			int x, y = myBackground->y1;
			if (myBackground->x1 >= myBackground->x2)
			{
				x = myBackground->x2;
			}
			else
			{
				x = myBackground->x1;
			}

			for (int i = 0; i <= length; i++) {
				myBackground->paper[y][x++] = DREW;
			}
		}
		else if (myBackground->x1 == myBackground->x2)
		{
			int length = abs(myBackground->y1 - myBackground->y2);
			int x = myBackground->x1, y;
			if (myBackground->y1 >= myBackground->y2)
			{
				y = myBackground->y2;
			}
			else
			{
				y = myBackground->y1;
			}

			for (int i = 0; i <= length; i++) {
				myBackground->paper[y++][x] = DREW;
			}
		}
		else
		{
			int m = (myBackground->y2 - myBackground->y1) / (myBackground->x2 - myBackground->x1);
			int range = abs(myBackground->x2 - myBackground->x1);
			int max_x = 0,
				max_y = 0;
#ifdef DEBUG
			cout << "m : " << m << endl;
#endif // DEBUG

			if (myBackground->x2 >= myBackground->x1) {
				max_x = myBackground->x2;
				max_y = myBackground->y2;
			}
			else {
				max_x = myBackground->x1;
				max_y = myBackground->y1;
			}
			if (m > 0) {
				for (size_t i = 0; i <= range; i++) {
					myBackground->paper[max_y--][max_x--] = DREW;
				}

			}
			else {
				for (size_t i = 0; i <= range; i++) {
					myBackground->paper[max_y++][max_x--] = DREW;
				}
			}
		}
	}
}
