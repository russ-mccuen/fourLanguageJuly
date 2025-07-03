while True:
    user_input = input("Please enter a number: ")

    try:
        num_check = int(user_input)
        if num_check % 15 == 0:
            print("Fizzbuzz")
        elif num_check % 3 == 0:
            print("Fizz")
        elif num_check % 5 == 0:
            print("Buzz")
        else:
            print(user_input)
        break
    except ValueError:
        print("Please only enter a number.")
