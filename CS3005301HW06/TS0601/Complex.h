#ifndef Complex_h
#define Complex_h

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complex
{
public:
    double realValue, imaginaryValue;

    Complex();
    //~Complex();
    Complex(double r);
    //~Complex(double r);
    Complex(double r, double i);
    //~Complex(double r, double i);

    double real() { return realValue; }
    double imag() { return imaginaryValue; }
    double norm() { return sqrt((realValue * realValue) + (imaginaryValue * imaginaryValue)); }

    friend double real(Complex c) { return c.realValue; }
    friend double imag(Complex c) { return c.imaginaryValue; }
    friend double norm(Complex c) { return sqrt((c.realValue * c.realValue) + (c.imaginaryValue * c.imaginaryValue)); }

    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);

    friend Complex operator+(double d, Complex c);
    friend Complex operator-(double d, Complex c);
    friend Complex operator*(double d, Complex c);
    friend Complex operator/(double d, Complex c);

    friend bool operator==(Complex c1, Complex c2);
    friend ostream& operator<<(ostream& strm, const Complex& c);
    friend istream& operator>>(istream& strm, Complex& c);
};
#endif /* Complex_h */
