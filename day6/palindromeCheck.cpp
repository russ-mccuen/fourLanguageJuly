#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "Please enter a word or phrase: ";
    string userInput;
    getline(cin, userInput);

    string cleaned = "";
    for (char c : userInput) {
        if (c != ' ') {
            cleaned += tolower(c);
        }
    }

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());

    if (cleaned == reversed) {
        cout << "This is a palindrome." << endl;
    } else {
        cout << "This is not a palindrome." << endl;
    }

    return 0;
}
