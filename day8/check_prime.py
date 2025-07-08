import math

def is_prime(num):
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True

def main():
    while True:
        user_input = input("Please enter a number and I will tell you if it is prime: ")

        try:
            user_num = int(user_input)
            if is_prime(user_num):
                print(f"{user_num} is a prime number.")
            else:
                print(f"{user_num} is not a prime number.")
            break
        except ValueError:
            print("\nPlease only enter a number.\n")

if __name__ == "__main__":
    main()
