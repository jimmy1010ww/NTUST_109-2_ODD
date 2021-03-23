#include "Fraction.h"

template < typename T >
T GCD(T a, T b) {
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}


void Fraction::setNumerator(int nu)
{
	Fraction::numerator = nu;
}

void Fraction::setDenominator(int de)
{
	Fraction::denominator = de;
}

void Fraction::getDouble()
{
	cout.clear();
	double ans = Fraction::numerator / (Fraction::denominator * 1.0);
	if ( ans - floor(ans) > 0)
	{
		cout << fixed << setprecision(6) << ans << endl;

	}
	else
	{
		cout << fixed << setprecision(0) << ans <<  endl;
	}
}
	

void Fraction::outputReducedFraction()
{
	cout.clear();
	int n = GCD(Fraction::numerator, Fraction::denominator);
	if (Fraction::denominator / n == 1)
	{
		cout << Fraction::numerator / n << endl;
	}
	else {
		cout << Fraction::numerator / n << "/" << Fraction::denominator / n << endl;
	}
}


