import math

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def print_primes_up_to(n):
    for i in range(2, n + 1):
        if is_prime(i):
            print(i, end=" ")
    print()

def get_user_input():
    while True:
        try:
            user_input = int(input("Enter a positive whole number: "))
            if user_input < 2:
                print("Please enter a number 2 or greater.")
                continue
            return user_input
        except ValueError:
            print("Please enter a valid number.")

def main():
    num = get_user_input()
    print(f"Prime numbers up to {num}:")
    print_primes_up_to(num)

if __name__ == "__main__":
    main()
