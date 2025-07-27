#include <iostream>
#include <string>

std::string compressString(const std::string& s) {
    if (s.empty()) {
        std::cout << "Original: \"\"\nCompressed: \"\"\n";
        return s;
    }

    std::string compressed;
    int count = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
        } else {
            compressed += s[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    compressed += s.back() + std::to_string(count);

    std::cout << "Original: " << s << "\n";
    std::cout << "Compressed: " << (compressed.length() < s.length() ? compressed : s) << "\n";

    return compressed.length() < s.length() ? compressed : s;
}

int main() {
    compressString("aabcccccaaa");
    compressString("abc");
    return 0;
}
