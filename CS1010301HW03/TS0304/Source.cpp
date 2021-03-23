#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
    int input_year;
    double k, i, n;

    cin >> input_year;

    while (!cin.eof())
    {
        i = 1, n = 0;
        k = 4 * pow(2, (input_year - 1900) / 10);
        while (n < k)
        {
            n += log2(i);
            i++;
        }
        i -= 2;
        cout << fixed << setprecision(0) << i << endl;

        cin >> input_year;
    }
}