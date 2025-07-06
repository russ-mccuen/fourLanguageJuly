import math

while True:
    user_input = input("Please enter a positive whole number: ")
    try:
        user_num = int(user_input)
        if user_num >= 1:
            fact = math.factorial(user_num)
            print(f"The factorial of {user_num} is {fact}.")
            break
        else:
            print("\nPlease only enter a positive whole number.\n")

    except ValueError:
        print("Please only enter a positive whole number.")
