#include <iostream>
#include <cmath>
#include <limits>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int userNum;

    while (true) {
        std::cout << "Please enter a number and I will tell you if it is prime: ";

        if (std::cin >> userNum) {
            if (isPrime(userNum)) {
                std::cout << userNum << " is a prime number." << std::endl;
            } else {
                std::cout << userNum << " is not a prime number." << std::endl;
            }
            break;
        } else {
            std::cout << "\nPlease only enter a number.\n" << std::endl;
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        }
    }

    return 0;
}
