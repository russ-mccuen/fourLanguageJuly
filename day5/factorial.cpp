#include <iostream>
#include <limits>
using namespace std;

int main() {
    int userNum;

    while (true) {
        cout << "\nPlease enter a positive whole number: ";
        
        if (cin >> userNum) {
            if (userNum < 1) {
                cout << "\nPlease only enter a positive whole number.\n";
                continue;
            }

            long long factorial = 1;
            for (int i = 1; i <= userNum; i++) {
                factorial *= i;
            }

            cout << "\nThe factorial of " << userNum << " is " << factorial << ".\n";
            break;

        } else {
            cout << "\nPlease only enter a positive whole number.\n";
            cin.clear(); // Reset error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }

    return 0;
}
