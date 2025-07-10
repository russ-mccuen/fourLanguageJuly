vowels = ['a', 'e', 'i', 'o', 'u']

user_input = input("Enter a word or words and I will count the number of vowels: ")
vowel_count = sum([1 for i in user_input.lower() if i in vowels])
print(f"The number of vowels in your input is {vowel_count} (not including y).")
