#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cout << "Enter a word or words and I will count the number of vowels: ";
    std::getline(std::cin, input);

    // Convert input to lowercase
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    int vowelCount = 0;
    for (char c : input) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }

    std::cout << "The number of vowels in your input is " << vowelCount << " (not including y)." << std::endl;
    return 0;
}
