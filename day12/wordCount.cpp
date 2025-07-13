#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    
    while (true) {
        std::cout << "Please type a sentence (one or more words): ";
        std::getline(std::cin, input);

        // Trim leading/trailing whitespace (optional step depending on input expectations)
        if (input.empty()) {
            std::cout << "Input cannot be empty.\n" << std::endl;
            continue;
        }

        std::istringstream stream(input);
        std::string word;
        int count = 0;

        while (stream >> word) {
            count++;
        }

        if (count == 1) {
            std::cout << "There is 1 word in your sentence." << std::endl;
        } else {
            std::cout << "There are " << count << " words in your sentence." << std::endl;
        }

        break;
    }

    return 0;
}
