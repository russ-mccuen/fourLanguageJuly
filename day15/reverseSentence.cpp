#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverse_sentence() {
    std::string input;

    while (true) {
        std::cout << "\nPlease type a sentence and I will reverse the word order:\n";
        std::getline(std::cin, input);

        // Trim leading/trailing whitespace
        if (input.find_first_not_of(" \t\n\r") == std::string::npos) {
            std::cout << "\nPlease type at least one character.\n";
            continue;
        }

        std::istringstream iss(input);
        std::vector<std::string> words;
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }

        std::reverse(words.begin(), words.end());

        std::ostringstream oss;
        for (size_t i = 0; i < words.size(); ++i) {
            oss << words[i];
            if (i < words.size() - 1) oss << " ";
        }

        return oss.str();
    }
}

void print_reversed(const std::string& reversed) {
    std::cout << reversed << std::endl;
}

int main() {
    std::string result = reverse_sentence();
    print_reversed(result);
    return 0;
}
