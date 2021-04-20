#include "VecNf.h"

//Construct a one-dimensional zero vector in default.
VecNf::VecNf()
{
	cnt = 1;
}

//Construct a cnt dimensional vector using the first cnt numbers in dest.
VecNf::VecNf(float* dest, int cnt)
{
	VecNf::cnt = cnt;
	for (size_t i = 0; i < cnt; i++)
	{
		a.push_back(dest[i]);
	}
}

//Construct a new vector from a VecNf.
VecNf::VecNf(const VecNf& rhs)
{
	VecNf::cnt = rhs.cnt;
	a.assign(rhs.a.begin(), rhs.a.end());
}

int VecNf::Size()
{
	return VecNf::cnt;
}

VecNf VecNf::operator+(VecNf c)
{
	VecNf tmp;
	tmp.cnt = c.cnt;
	if (cnt == c.cnt)
	{
		for (size_t i = 0; i < cnt; i++)
		{
			tmp.a.push_back(VecNf::a[i] + c.a[i]);
		}
		return tmp;
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
}

VecNf VecNf::operator-(VecNf c)
{
	VecNf tmp;
	tmp.cnt = c.cnt;
	if (cnt == c.cnt)
	{
		for (size_t i = 0; i < cnt; i++)
		{
			tmp.a.push_back(VecNf::a[i] - c.a[i]);
		}
		return tmp;
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
}

float VecNf::operator*(VecNf c)
{
	float sum = 0;
	if (cnt == c.cnt)
	{
		for (size_t i = 0; i < cnt; i++)
		{
			sum += a[i] * c.a[i];
		}
		return sum;
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		return sum;
	}
}

VecNf VecNf::operator/(VecNf c)
{
	VecNf tmp;
	tmp.cnt = c.cnt;
	if (cnt == c.cnt)
	{
		for (size_t i = 0; i < cnt; i++)
		{
			tmp.a.push_back(VecNf::a[i] / c.a[i]);
		}
		return tmp;
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
}

void VecNf::operator=(VecNf v)
{
	VecNf::cnt = v.cnt;
	a.clear();
	cout << "ASSIGNMENT!!!" << endl;
	a.assign(v.a.begin(), v.a.end());
}

float& VecNf::operator[](int index)
{
	return VecNf::a[index];
}

VecNf operator*(float ratio, VecNf c)
{

	for (size_t i = 0; i < c.cnt; i++)
	{
		c.a[i] *= ratio;
	}
	return c;
}
