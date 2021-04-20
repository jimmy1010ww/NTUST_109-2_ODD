#include "Complex.h"

//construct a complex number where both realValue and imaginaryValue are 0.
Complex::Complex()
{
    realValue = 0;
    imaginaryValue = 0;
}

//construct a complex number where the realValue is r and the imaginaryValue is 0.
Complex::Complex(double r)
{
    realValue = r;
    imaginaryValue = 0;
}

//construct a complex number where the realValue is r and the imaginaryValue is i.
Complex::Complex(double r, double i)
{
    realValue = r;
    imaginaryValue = i;
}

Complex Complex::operator+(Complex c)
{
    double opt_r, opt_i;
    opt_r = realValue + c.realValue;
    opt_i = imaginaryValue + c.imaginaryValue;

    return Complex(opt_r, opt_i);
}

Complex Complex::operator-(Complex c)
{
    double opt_r, opt_i;
    opt_r = realValue - c.realValue;
    opt_i = imaginaryValue - c.imaginaryValue;

    return Complex(opt_r, opt_i);
}

Complex Complex::operator*(Complex c)
{
    double opt_r, opt_i;
    opt_r = (realValue * c.realValue) - (imaginaryValue * c.imaginaryValue);
    opt_i = (imaginaryValue * c.realValue) + (realValue * c.imaginaryValue);

    return Complex(opt_r, opt_i);
}

Complex Complex::operator/(Complex c)
{
    double opt_r = 0, opt_i = 0;
    if (c.realValue > 0 || c.imaginaryValue > 0) {
        opt_r = ((realValue * c.realValue) + (imaginaryValue * c.imaginaryValue)) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
        opt_i = ((imaginaryValue * c.realValue) - (realValue * c.imaginaryValue)) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
    }
    else
    {
        cout << "Complex division error" << endl;
    }
    return Complex(opt_r, opt_i);
}

Complex operator+(double d, Complex c)
{
    double opt_r, opt_i;
    opt_r = d + c.realValue;
    opt_i = c.imaginaryValue;
    return Complex(opt_r, opt_i);
}

Complex operator-(double d, Complex c)
{
    double opt_r, opt_i;
    opt_r = d - c.realValue;
    opt_i = 0 - c.imaginaryValue;
    return Complex(opt_r, opt_i);
}

Complex operator*(double d, Complex c)
{
    double opt_r, opt_i;
    opt_r = (d * c.realValue) - (0.0 * c.imaginaryValue);
    opt_i = (0.0 * c.realValue) + (d * c.imaginaryValue);
    return Complex(opt_r, opt_i);
}

Complex operator/(double d, Complex c)
{
    double opt_r = 0, opt_i = 0;
    if (c.realValue > 0) {
        opt_r = ((d * c.realValue) + (0.0 * c.imaginaryValue)) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
        opt_i = ((0.0 * c.realValue) - (d * c.imaginaryValue)) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
    }
    else
    {
        cout << "Complex division error" << endl;
    }
    return Complex(opt_r, opt_i);

}

bool operator==(Complex c1, Complex c2)
{
    if ((c1.realValue == c2.realValue) && (c1.imaginaryValue == c2.imaginaryValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& strm, const Complex& c)
{
    strm << c.realValue << " + " << c.imaginaryValue << "*i";
    return strm;
}

istream& operator>>(istream& strm, Complex& c)
{
    char input[3];
    string i;
    if ((strm >> input[0] >> input[1] >> c.realValue >> input[2] >> i) &&
        (isalpha(input[0]) && (input[1] == '=') && (input[2] == '+')))
    {
        i.pop_back();
        i.pop_back();
        c.imaginaryValue = stod(i.c_str());
    }
    return strm;
}
