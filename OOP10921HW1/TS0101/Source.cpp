#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    double n, guess, last_guess;

    cin >> n;
    last_guess = 0;

    while (!cin.eof()) {
        guess = n / 2.0;
        while (!(abs(guess - last_guess) < 0.01)) {
            last_guess = guess;
            guess = (guess + n / guess) / 2;
        }
        cout << fixed << setprecision(2) << guess << endl;
        cin >> n;
    }

}

