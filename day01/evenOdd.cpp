#include <iostream>
#include <limits>
using namespace std;

int main() {
    double input;

    while (true) {
        cout << "Enter a whole number (no decimals): ";

        if (!(cin >> input)) {
            cout << "Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (input != static_cast<int>(input)) {
            cout << "Please enter a whole number with no decimals." << endl;
            continue;
        }

        int number = static_cast<int>(input);
        if (number % 2 == 0) {
            cout << "The number is even." << endl;
        } else {
            cout << "The number is odd." << endl;
        }
        break;
    }

    return 0;
}
