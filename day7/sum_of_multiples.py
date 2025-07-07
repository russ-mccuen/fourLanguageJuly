while True:
    try:
        user_input = input("Please enter a positive whole number: ")
        user_num = int(user_input)
        if user_num < 1:
            print("\nPlease enter a positive whole number (a number greater than zero.)\n")
            continue
        user_sum = 0
        for i in range(1, user_num):
            if i % 3 == 0 or i % 5 == 0:
                user_sum += i
        print(f"The sum of multiples of 3 or 5 below {user_input} is {user_sum}.")
        break
    except ValueError:
        print("\nPlease only enter a positive whole number.\n")
