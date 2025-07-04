# I thought about input validation, but no point
# since all input will be a string
# Also decided to just leave blanks and one-letter
# input as is

word = input("Please enter a word: ")
print(word[::-1])
