#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void printPrimesUpTo(int n) {
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int getUserInput() {
    int num;
    while (true) {
        cout << "Enter a positive whole number: ";
        cin >> num;

        if (cin.fail() || num < 2) {
            cout << "Please enter a valid number (2 or greater)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return num;
}

int main() {
    int userNum = getUserInput();
    cout << "Prime numbers up to " << userNum << ":" << endl;
    printPrimesUpTo(userNum);
    return 0;
}
