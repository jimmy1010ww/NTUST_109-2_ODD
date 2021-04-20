#ifndef VecNf_H
#define VecNf_H

#include <iostream>
#include <vector>

using namespace std;

class VecNf
{
public:
	vector <float> a;
	int cnt;
	//Construct a one - dimensional zero vector in default.
	VecNf();
	//Construct a cnt dimensional vector using the first cnt numbers in dest.
	VecNf(float* dest, int cnt);
	//Construct a new vector from a VecNf.
	VecNf(const VecNf& rhs);

	int Size();

	VecNf operator+(VecNf v);
	VecNf operator-(VecNf v);
	float operator*(VecNf v);
	VecNf operator/(VecNf v);

	void operator=(VecNf v);
	float& operator[](int index);
	friend VecNf operator*(float ratio ,VecNf c);
};

#endif