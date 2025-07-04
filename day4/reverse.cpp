#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "Please enter a word: ";
    string word;
    getline(cin, word);
    reverse(word.begin(), word.end());
    cout << word;
}
