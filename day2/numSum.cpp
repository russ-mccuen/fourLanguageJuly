#include <iostream>
#include <limits>
using namespace std;

int main() {
    int user_input;

    while (true) {
        cout << "Enter a positive integer: ";

        if (cin >> user_input) {
            if (user_input < 0) {
                cout << "Please enter a positive whole number: " << endl;
                continue;
            }

            int sum = 0;
            int temp = user_input;

            while (temp > 0) {
                sum += temp % 10;  // Add last digit
                temp /= 10;        // Remove last digit
            }

            cout << "The sum is " << sum << endl;
            break;

        } else {
            cout << "Please enter a positive whole number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
