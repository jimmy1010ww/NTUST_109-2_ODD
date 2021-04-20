#include "Shisensho.h"
//#define DEBUG

Shisensho::Shisensho()
{
	Shisensho::pos1.x = 0;
	Shisensho::pos2.x = 0;
	Shisensho::pos1.y = 0;
	Shisensho::pos2.y = 0;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j] = 0;
		}
	}
}

void Shisensho::readMap()
{
	for (size_t i = 1; i <= SIZE; i++)
	{
		for (size_t j = 1; j <= SIZE; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Shisensho::printMap()
{
	for (size_t i = 1; i <= SIZE; i++)
	{
		for (size_t j = 1; j <= SIZE; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;	
	}
	cout << endl;
}

void Shisensho::getPair(int x_1, int y_1, int x_2, int y_2)
{	
	Shisensho::pos1.x = x_1;
	Shisensho::pos2.x = x_2;
	Shisensho::pos1.y = y_1;
	Shisensho::pos2.y = y_2;

#ifdef DEBUG
	cout << "( " << pos1.x << "," << pos1.y << " ) = " << "[ " << map[pos1.y][pos1.x] << " ]" << endl;
	cout << "( " << pos2.x << "," << pos2.y << " ) = " << "[ " << map[pos2.y][pos2.x] << " ]" << endl;
#endif // DEBUG

}

bool Shisensho::check_logic()
{
	if (pos1.x > 5 || pos1.x < 0 || pos2.x > 5 || pos2.x < 0 || pos2.x > 5 || pos2.x < 0 || pos2.y > 5 || pos2.y < 0)
	{
		return false;
	}

	Shisensho::pos1.x++;
	Shisensho::pos2.x++;
	Shisensho::pos1.y++;
	Shisensho::pos2.y++;
	

	if (map[pos1.y][pos1.x] != map[pos2.y][pos2.x] || map[pos1.y][pos1.x] == 0 || map[pos2.y][pos2.x] == 0 || pos1.x == pos2.x && pos1.y == pos2.y)	//檢查例外
	{
		return false;
	}
	
	if (pos1.x == pos2.x || pos1.y == pos2.y)
	{
		if (check_line(pos1.x, pos1.y, pos2.x, pos2.y))
		{
			map[pos1.y][pos1.x] = 0;
			map[pos2.y][pos2.x] = 0;
			return true;
		}
	}
	
	if (check_one_turn(pos1.x, pos1.y, pos2.x, pos2.y) || check_two_turn(pos1.x, pos1.y, pos2.x, pos2.y))
	{
		map[pos1.y][pos1.x] = 0;
		map[pos2.y][pos2.x] = 0;
		return true;
	}
	return false;
}

bool Shisensho::check_line(int x_1, int y_1, int x_2, int y_2)
{
	int min_x = min(x_1, x_2);
	int max_x = max(x_1, x_2);
	int min_y = min(y_1, y_2);
	int max_y = max(y_1, y_2);

	if (min_x == max_x)
	{
		if (max_y - min_y == 1)
		{
			return true;
		}

		for (size_t i = min_y + 1; i < max_y; i++)
		{
			if (map[i][x_1] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (min_y == max_y)
	{
		if (max_x - min_x == 1)
		{
			return true;
		}

		for (size_t i = min_x + 1; i < max_x; i++)
		{
			if (map[y_1][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Shisensho::check_one_turn(int x_1, int y_1, int x_2, int y_2)
{
	//考慮一次轉彎，有點像正方形
	int tmpX1 = x_1;
	int tmpY1 = y_2;
	int tmpX2 = x_2;
	int tmpY2 = y_1;
	if ((check_line(tmpX1, tmpY1, x_1, y_1) && check_line(tmpX1, tmpY1, x_2, y_2) && map[tmpY1][tmpX1] == 0)
		|| (check_line(tmpX2, tmpY2, x_1, y_1) && check_line(tmpX2, tmpY2, x_2, y_2) && map[tmpY2][tmpX2] == 0))
	{
		return true;
	}
	return false;
}

bool Shisensho::check_two_turn(int x_1, int y_1, int x_2, int y_2)
{
	int tmpX1 = 0;
	int tmpY1 = 0;
	int tmpX2 = 0;
	int tmpY2 = 0;
	for (size_t i = 0; i < 8; i++)
	{
		tmpX1 = x_1;
		tmpX2 = x_2;
		tmpY1 = i;
		tmpY2 = i;
		if (check_line(tmpX1, tmpY1, tmpX2, tmpY2) && check_line(tmpX1, tmpY1, x_1,y_1) && check_line(tmpX2, tmpY2, x_2, y_2)
			&& map[tmpY1][tmpX1] == 0 && map[tmpY2][tmpX2] == 0)
		{
			return true;
		}

		tmpX1 = i;
		tmpX2 = i;
		tmpY1 = y_1;
		tmpY2 = y_2;
		if (check_line(tmpX1, tmpY1, tmpX2, tmpY2) && check_line(tmpX1, tmpY1, x_1, y_1) && check_line(tmpX2, tmpY2, x_2, y_2)
			&& map[tmpY1][tmpX1] == 0 && map[tmpY2][tmpX2] == 0)
		{
			return true;
		}
	}
	return false;
}


