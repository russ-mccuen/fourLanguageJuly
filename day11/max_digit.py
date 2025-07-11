while True:
    user_input = input("Enter a number and I will extract the maximum digit: ")
    try:
        int(user_input)  # raises ValueError if not all digits
        print(max(user_input))
        break
    except ValueError:
        print("Please enter only digits.")
