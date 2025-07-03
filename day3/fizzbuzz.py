while True:
    user_input = input("Please enter a number: ")

    try:
        num_check = int(user_input)
        for i in range(1, num_check + 1):
            if i % 15 == 0:
                print("Fizzbuzz")
            elif i % 3 == 0:
                print("Fizz")
            elif i % 5 == 0:
                print("Buzz")
            else:
                print(i)
        break
    except ValueError:
        print("Please only enter a number.")
