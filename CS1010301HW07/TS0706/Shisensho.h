#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

#define SIZE 6

using namespace std;

class Shisensho
{
public:
	typedef struct pos {
		int x;
		int y;
	}Pos;

	int map[SIZE + 2][SIZE + 2];
	Pos pos1, pos2;

	Shisensho();
	void readMap();
	void printMap();
	void getPair(int x_1, int y_1, int x_2, int y_2);
	bool check_logic();
	bool check_line(int x_1, int y_1, int x_2, int y_2);
	bool check_one_turn(int x_1, int y_1, int x_2, int y_2);
	bool check_two_turn(int x_1, int y_1, int x_2, int y_2);
};

