#include <iostream>
#include <iomanip>
#include <vector>
#include "Shisensho.h"
using namespace std;

int main()
{
	Shisensho myShisensho;
	myShisensho.readMap();
	//myShisensho.printMap();
	int x1, x2, y1, y2;
	
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		myShisensho.getPair(x1 , y1 , x2 , y2);
		if (myShisensho.check_logic())
		{
			cout << "pair matched" << endl;
		}
		else
		{
			cout << "bad pair" << endl;
		}
		//myShisensho.printMap();
	}


}