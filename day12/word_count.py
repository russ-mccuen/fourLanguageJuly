# Every once in awhile I remember to create functions and __main__ !!!

def count_words():
    while True:
        sentence = input("Please type a sentence (one or more words): ").strip()
        if not sentence:
            print("Input cannot be empty.\n")
            continue

        words = sentence.split()
        count = len(words)

        print(f"There {'is' if count == 1 else 'are'} {count} word{'s' if count != 1 else ''} in your sentence.")
        break

if __name__ == "__main__":
    count_words()
