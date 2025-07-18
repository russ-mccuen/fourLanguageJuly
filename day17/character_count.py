def character_count():
    while True:
        user_input = input("\nEnter a word or phrase: ").strip()
        if not user_input:
            print("\nPlease enter at least one character.\n")
            continue
        char = input("Enter a single character to count: ").strip()
        if len(char) != 1:
            print("\nPlease enter exactly one character.\n")
            continue
        count = user_input.count(char)
        print(f"\nThe character '{char}' appears {count} time(s) in your input.")
        break

if __name__ == "__main__":
    character_count()
