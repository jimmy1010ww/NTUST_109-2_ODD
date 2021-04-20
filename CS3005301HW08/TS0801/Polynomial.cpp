#include "Polynomial.h"

Polynomial::Polynomial()
{
	Polynomial::size = 1;
	Polynomial::myArrayPointer = NULL;
	Polynomial::myArrayPointer = new double[size];
	myArrayPointer[0] = 0;
}

Polynomial::Polynomial(double* param, int size)
{
	if (size <= 0)
	{
		Polynomial::size = 1;
		Polynomial::myArrayPointer = NULL;
		Polynomial::myArrayPointer = new double[size];
		myArrayPointer[0] = 0;
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			if (param[i] != 0)
			{
				Polynomial::size = i;
			}
		}
		Polynomial::size++;
		Polynomial::myArrayPointer = NULL;
		Polynomial::myArrayPointer = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			myArrayPointer[i] = param[i];
		}
	}

}

//Copy Constructor
Polynomial::Polynomial(const Polynomial& in)
{
	size = in.size;
	Polynomial::myArrayPointer = NULL;
	myArrayPointer = new double[in.size];
	for (size_t i = 0; i < in.size; i++)
	{
		myArrayPointer[i] = in.myArrayPointer[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] myArrayPointer;
}

int Polynomial::mySize()
{
	int return_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (myArrayPointer[i] != 0.0)
		{
			return_size = i;
		}
	}
	return return_size + 1;
}

double evaluate(const Polynomial& poly, const double& var)
{
	double sum = 0;
	for (size_t i = 0; i < poly.size; i++)
	{
		sum += (pow(var, i) * poly.myArrayPointer[i]);
	}
	return sum;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
	if (this == &rhs)
		return *this; //self assignment
	if (myArrayPointer != NULL)
		delete[] myArrayPointer; //clean up already allocated memory

	size = rhs.size;
	myArrayPointer = new double[size];
	for (size_t i = 0; i < size; i++)
	{
		myArrayPointer[i] = rhs.myArrayPointer[i];
	}

	return *this;
}

double& Polynomial::operator[](int index)
{
	if (index < size && index >= 0)
	{
		return myArrayPointer[index];
	}
	else
	{
		int tmp_inedx = index + 1;
		doublePtr tmp_array = new double[tmp_inedx];
		copy(myArrayPointer, myArrayPointer + size, tmp_array);
		delete[] myArrayPointer;
		myArrayPointer = new double[tmp_inedx];
		size = tmp_inedx;
		copy(tmp_array, tmp_array + tmp_inedx, myArrayPointer);
		return myArrayPointer[index];
	}
}

Polynomial Polynomial::operator+(const Polynomial& rhs)
{
	int tmp_size = size;
	if (size >= rhs.size)
	{
		tmp_size = size;
	}
	else
	{
		tmp_size = rhs.size;
	}

	doublePtr ans;
	ans = new double[tmp_size];
	for (int i = 0; i < tmp_size; i++)
	{
		ans[i] = 0.0;
	}

	for (size_t i = 0; i < rhs.size; i++)
	{
		ans[i] += rhs.myArrayPointer[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		ans[i] += myArrayPointer[i];
	}

	return Polynomial(ans, tmp_size);
}

Polynomial Polynomial::operator-(const Polynomial& rhs)
{
	int tmp_size = size;
	if (size >= rhs.size)
	{
		tmp_size = size;
	}
	else
	{
		tmp_size = rhs.size;
	}

	doublePtr ans;
	ans = new double[tmp_size];
	for (int i = 0; i < tmp_size; i++)
	{
		ans[i] = 0.0;
	}

	for (size_t i = 0; i < size; i++)
	{
		ans[i] = myArrayPointer[i];
	}
	for (size_t i = 0; i < rhs.size; i++)
	{
		ans[i] -= rhs.myArrayPointer[i];
	}
	return Polynomial(ans, tmp_size);
}

Polynomial Polynomial::operator*(const Polynomial& rhs)
{
	int max_power = (size - 1) + (rhs.size - 1) + 1;
	doublePtr ans;
	ans = new double[max_power];
	for (int i = 0; i < max_power; i++)
	{
		ans[i] = 0.0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rhs.size; j++)
		{
			int index = i + j;
			ans[index] += (myArrayPointer[i] * rhs.myArrayPointer[j]);
		}
	}
	return  Polynomial(ans, max_power);
}

Polynomial operator+(const Polynomial& tar, double rhs)
{
	Polynomial tmp = tar;
	tmp.myArrayPointer[0] += rhs;
	return Polynomial(tmp.myArrayPointer, tmp.size);
}

Polynomial operator+(double lhs, const Polynomial& rhs)
{
	Polynomial tmp = rhs;
	tmp.myArrayPointer[0] += lhs;
	return Polynomial(tmp.myArrayPointer, tmp.size);
}

Polynomial operator-(const Polynomial& tar, double rhs)
{
	Polynomial tmp = tar;
	tmp.myArrayPointer[0] = tmp.myArrayPointer[0] - rhs;
	return Polynomial(tmp.myArrayPointer, tmp.size);

}

Polynomial operator-(double lhs, const Polynomial& rhs)
{
	Polynomial tmp = rhs;
	tmp.myArrayPointer[0] = lhs - tmp.myArrayPointer[0];
	for (size_t i = 1; i < rhs.size; i++)
	{
		tmp.myArrayPointer[i] = -tmp.myArrayPointer[i];
	}
	return Polynomial(tmp.myArrayPointer, tmp.size);
}

Polynomial operator*(const Polynomial& tar, double rhs)
{
	Polynomial tmp = tar;
	for (size_t i = 0; i < tar.size; i++)
	{
		tmp.myArrayPointer[i] = tar.myArrayPointer[i] * rhs;
	}
	return Polynomial(tmp.myArrayPointer, tmp.size);
}

Polynomial operator*(double lhs, const Polynomial& rhs)
{
	Polynomial tmp = rhs;
	for (size_t i = 0; i < rhs.size; i++)
	{
		tmp.myArrayPointer[i] = lhs * rhs.myArrayPointer[i];
	}
	return Polynomial(tmp.myArrayPointer, tmp.size);
}

