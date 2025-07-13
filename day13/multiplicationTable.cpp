#include <iostream>
#include <string>
#include <sstream>

void printMultiplicationTable() {
    std::string input;
    int number;

    while (true) {
        std::cout << "Please enter a number and I will print\n"
                     "the multiplication table, to 10, for that number: ";
        std::getline(std::cin, input);
        std::cout << std::endl;

        std::stringstream ss(input);
        if (ss >> number && ss.eof()) {
            for (int i = 1; i <= 10; ++i) {
                std::cout << number << " x " << i << " = " << number * i << std::endl;
            }
            break;
        } else {
            std::cout << "\nPlease enter a number.\n\n";
        }
    }
}

int main() {
    printMultiplicationTable();
    return 0;
}
