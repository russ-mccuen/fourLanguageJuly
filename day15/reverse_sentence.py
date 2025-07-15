def reverse_sentence():
    while True:
        user_input = input("\nPlease type I sentence and I will reverse it!\n")
        if not user_input.strip():
            print("\nPlease type at least one character.\n")
            continue

        return (user_input[::-1])
    
def print_reversed(user_string):
    print(user_string)

if __name__ == "__main__":
    user_sentence = reverse_sentence()
    print_reversed(user_sentence)
