#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string input;
    
    while (true) {
        std::cout << "Enter a number and I will extract the maximum digit: ";
        std::cin >> input;

        bool is_valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            char max_digit = '0';
            for (char c : input) {
                if (c > max_digit) {
                    max_digit = c;
                }
            }
            std::cout << "The maximum digit is: " << max_digit << "\n";
            break;
        } else {
            std::cout << "Please enter only digits.\n";
        }
    }

    return 0;
}
