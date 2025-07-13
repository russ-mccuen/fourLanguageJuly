def print_multiplication_table():
    while True:
        user_input = input("Please enter a number and I will print\nthe multiplication table, to 10, for that number: ")
        try:
            number = int(user_input)
            for i in range(1, 11):
                print(f"{number} x {i} = {number * i}")
            break    
        except ValueError:
            print("\nPlease enter a number.\n")

if __name__ == "__main__":
    print_multiplication_table()
