#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	Point::vertical += x;
	Point::horizontal += y;
}
void Point::Rotate()
{
	int x, y;
	x = Point::vertical * -1;
	y = Point::horizontal;
	Point::horizontal = x;
	Point::vertical = y;
}

