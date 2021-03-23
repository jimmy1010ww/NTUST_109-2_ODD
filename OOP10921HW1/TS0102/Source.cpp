#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned long long A, x, y, z;; //sec

    cin >> A;

    while (!cin.eof())
    {
        x = A / 3600;
        y = (A % 3600) / 60;
        z = ((A % 3600) % 60);
        cout << x << " hours " << y << " minutes and " << z << " seconds" << endl;
        cin >> A;
    }
}