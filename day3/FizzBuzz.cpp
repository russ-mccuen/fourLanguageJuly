#include <iostream>
#include <limits>
using namespace std;

int main() {
    int numCheck;

    while (true) {
        cout << "Please enter a number: ";

        if (cin >> numCheck) {
            for (int i = 1; i <= numCheck; i++) {
                if (i % 15 == 0) {
                    cout << "Fizzbuzz" << endl;
                } else if (i % 3 == 0) {
                    cout << "Fizz" << endl;
                } else if (i % 5 == 0) {
                    cout << "Buzz" << endl;
                } else {
                    cout << i << endl;
                }
            }
            break;
        } else {
            cout << "Please only enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
