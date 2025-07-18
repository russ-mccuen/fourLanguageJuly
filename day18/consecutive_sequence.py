import random

def longest_consecutive(nums):
    num_set = set(nums)
    longest = 0

    for num in num_set:
        if num - 1 not in num_set:
            current = num
            streak = 1
            while current + 1 in num_set:
                current += 1
                streak += 1
            longest = max(longest, streak)

    return longest

def main():
    length = random.randint(10, 30)
    nums = random.sample(range(0, 100), length)
    print("Input:", nums)
    print("Longest consecutive sequence length:", longest_consecutive(nums))

if __name__ == "__main__":
    main()
