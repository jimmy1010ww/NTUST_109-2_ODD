#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point();
	~Point();

	void Set(int x, int y);
	void Move(int x, int y);
	void Rotate();
	void Reflect();
	int GetHorizontal() const { return x; }
	int GetVertical () const { return y; }
};

#endif //Point_H