#include <iostream>
#include <cmath>
#include "PrimeNumber.h"

using namespace std;

int main()
{
    PrimeNumber p1(3), p2(13);
    PrimeNumber a = --p1;
    PrimeNumber b = p2--;
    cout << a.get() << endl;
    cout << p1.get() << endl;
    cout << b.get() << endl;
    cout << p2.get() << endl;
    return 0;
}
