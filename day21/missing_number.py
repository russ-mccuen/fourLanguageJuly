import random

def missing_number(nums):
    n = len(nums)
    expected_sum = n * (n + 1) // 2  # sum of 0 to n
    return expected_sum - sum(nums)

def generate_test_case():
    n = random.randint(10, 30)
    full = list(range(n + 1))  # 0 to n inclusive
    missing = random.choice(full)
    full.remove(missing)
    random.shuffle(full)
    return full, missing

def main():
    nums, actual_missing = generate_test_case()
    print("Input:", nums)
    print("Expected missing number:", actual_missing)
    print("Computed missing number:", missing_number(nums))

if __name__ == "__main__":
    main()
