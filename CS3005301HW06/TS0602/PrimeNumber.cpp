#include "PrimeNumber.h"

PrimeNumber& PrimeNumber::operator++()
{
    value++;
    while (true)
    {
        int flag = 1;
        for (int i = 2; i < value; i++) {
            if (value % i == 0)
            {
                flag = 0;
            }
        }
        
        if (flag == 1) {
            break;
        }
        else
        {
            value++;
        }
    }
    return *this;

}

PrimeNumber PrimeNumber::operator++(int)
{
    PrimeNumber Origin(value);
    value++;
    while (true)
    {
        int flag = 1;
        for (int i = 2; i < value; i++) {
            if (value % i == 0)
            {
                flag = 0;
            }
        }
        
        if (flag == 1) {
            break;
        }
        else
        {
            value++;
        }
    }
    return Origin;
}

PrimeNumber& PrimeNumber::operator--()
{
    value--;
    while (true)
    {
        int flag = 1;
        for (int i = 2; i < value; i++) {
            if (value % i == 0)
            {
                flag = 0;
            }
        }
        
        if (flag == 1) {
            break;
        }
        else
        {
            value--;
        }
    }

    return *this;
}

PrimeNumber PrimeNumber::operator--(int)
{
    PrimeNumber Origin(value);
    value--;
    while (true)
    {
        int flag = 1;
        for (int i = 2; i < value; i++) {
            if (value % i == 0)
            {
                flag = 0;
            }
        }
        
        if (flag == 1) {
            break;
        }
        else
        {
            value--;
        }
    }
    return Origin;
}
