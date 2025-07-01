while True:
    user_input = input("Enter a whole number (no decimals): ")
    try:
        number = int(user_input)
        if number % 2 == 0:
            print("The number is even.")
        else:
            print("The number is odd.")
        break

    except ValueError:
        print("Please enter a whole number.")
