from collections import Counter

user_input = input("Enter a sentence: ").lower()
words = user_input.split()
word_counts = Counter(words)

for word, count in word_counts.items():
    print(f"{word}: {count}")
