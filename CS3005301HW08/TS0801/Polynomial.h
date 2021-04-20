#pragma once
#include <iostream>
#include <cmath>
using namespace std;

typedef double* doublePtr;

class Polynomial
{
private:
	doublePtr myArrayPointer;
	int size;

public:
	//Construct a zero polynomial.
	Polynomial();
	//Construct a one - dimensional polynomial based on the given coefficients which have the given size.
	Polynomial(double* param, int size);
	//Copy constructor
	Polynomial(const Polynomial& in);
	~Polynomial();

	//Return the number of terms of the polynomial.
	int mySize();
	//Return the value of the polynomial after substituting var into the variables.
	friend double evaluate(const Polynomial& poly, const double& var);

	Polynomial& operator=(const Polynomial& rhs);
	double& operator[](int index);

	Polynomial operator+(const Polynomial& rhs);
	Polynomial operator-(const Polynomial& rhs);
	Polynomial operator*(const Polynomial& rhs);

	friend Polynomial operator+(double lhs, const Polynomial& rhs);
	friend Polynomial operator+(const Polynomial& tar, double rhs);

	friend Polynomial operator-(double lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& tar, double rhs);

	friend Polynomial operator*(double lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& tar, double rhs);
};

