#include <iostream>
#include <limits>
using namespace std;

int main() {
    int userNum;

    while (true) {
        cout << "Please enter a positive whole number: ";

        if (cin >> userNum) {
            if (userNum <= 1) {
                cout << "\nPlease only enter a positive whole number greater than 1.\n";
                continue;
            }

            int sum = 0;
            for (int i = 1; i < userNum; i++) {
                if (i % 3 == 0 || i % 5 == 0) {
                    sum += i;
                }
            }

            cout << "The sum of multiples of 3 or 5 below " << userNum << " is " << sum << ".\n";
            break;

        } else {
            cout << "\nPlease only enter a positive whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
