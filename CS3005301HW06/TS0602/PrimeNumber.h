#ifndef PrimeNumber_H
#define PrimeNumber_H

#include <iostream>
#include <cmath>
using namespace std;

class PrimeNumber
{

public:
    int value;
    int get() { return value; }
    PrimeNumber() { PrimeNumber::value = 1; }
    PrimeNumber(int _value) { PrimeNumber::value = _value; }

    PrimeNumber& operator++();
    PrimeNumber operator++(int);
    PrimeNumber& operator--();
    PrimeNumber operator--(int);


};

#endif
