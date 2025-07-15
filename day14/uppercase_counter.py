def check_uppercase():
    while True:
        user_input = input(("Please type a sentence and I will tell you how many uppercase letters it has:\n"))
        
        if not user_input.strip():
            print("\nPlease type at least one character.\n")
            continue

        upper_count = sum(1 for letter in user_input if letter.isupper())
        return upper_count
    
def print_upper_count(count):
    print(f"The number of upper case letters is {count}.")

if __name__ == "__main__":
    upper_count = check_uppercase()
    print_upper_count(upper_count)
