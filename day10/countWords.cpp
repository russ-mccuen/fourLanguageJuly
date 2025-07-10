#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

int main() {
    std::string input;
    std::map<std::string, int> wordCounts;

    // Prompt the user for input
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    // Convert input to lowercase
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Use a stringstream to split the input into words
    std::stringstream ss(input);
    std::string word;

    // Extract words and count them
    while (ss >> word) {
        wordCounts[word]++;
    }

    // Output each word and its frequency
    for (const auto& pair : wordCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
