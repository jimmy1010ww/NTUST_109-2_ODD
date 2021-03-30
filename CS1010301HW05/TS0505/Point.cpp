#include "Point.h"

Point::Point(){
	Point::x = 0;
	Point::y = 0;
}

Point::~Point() {

}


void Point::Set(int x, int y)
{
	Point::x = x;
	Point::y = y;
}

void Point::Move(int x, int y)
{
	Point::x += x;
	Point::y += y;
}

void Point::Rotate()
{
	int x, y;
	x = Point::y;
	y = Point::x * -1;
	Point::x = x;
	Point::y = y;
}

void Point::Reflect()
{
	int x, y;
	x = Point::x * -1;
	y = Point::y * -1;
	Point::x = x;
	Point::y = y;
}

