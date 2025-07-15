#include <iostream>
#include <string>
#include <cctype>

int getUpperCount() {
    std::string input;

    while (true) {
        std::cout << "Please type a sentence and I will tell you how many uppercase letters it has:\n";
        std::getline(std::cin, input);

        // Trim check: if input is only whitespace or empty
        if (input.find_first_not_of(' ') == std::string::npos) {
            std::cout << "\nPlease type at least one character.\n\n";
            continue;
        }

        int count = 0;
        for (char c : input) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                count++;
            }
        }
        return count;
    }
}

void printUpperCount(int count) {
    std::cout << "The number of uppercase letters is " << count << ".\n";
}

int main() {
    int upperCount = getUpperCount();
    printUpperCount(upperCount);
    return 0;
}
