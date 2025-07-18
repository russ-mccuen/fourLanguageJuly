#include <iostream>
#include <string>

int main() {
    std::string input;
    char target;

    // Get non-empty sentence from user
    while (true) {
        std::cout << "Please enter a sentence:\n";
        std::getline(std::cin, input);

        if (!input.empty()) break;
        std::cout << "\nPlease enter at least one character.\n\n";
    }

    // Get character to search for
    std::cout << "\nPlease enter a character to count:\n";
    std::cin >> target;

    // Count occurrences
    int count = 0;
    for (char c : input) {
        if (c == target) count++;
    }

    std::cout << "\nThe character '" << target << "' appears " << count << " time"
              << (count == 1 ? "." : "s.") << std::endl;

    return 0;
}
