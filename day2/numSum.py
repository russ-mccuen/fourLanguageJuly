# write a program that prompts the user to enter
# a positive integer, then display the sum of it's digits

user_input = input("Enter a positive integer: ")
while not user_input.isdigit():
    user_input = input("Please enter a valid positive whole number: ")

user_ints = [int(x) for x in user_input]
print("The sum is", sum(user_ints))
