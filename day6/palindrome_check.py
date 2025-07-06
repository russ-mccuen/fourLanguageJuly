user_input = input("Please enter a word or phrase: ")
cleaned = user_input.replace(" ", "").lower()

if cleaned == cleaned[::-1]:
    print("This is a palindrome.")
else:
    print("This is not a palindrome.")
