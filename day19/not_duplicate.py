import random

def single_number(nums):
    result = 0
    for num in nums:
        result ^= num  # XOR cancels out duplicates
    return result

def generate_test_case():
    length = random.randint(10, 20)
    # random.sample returns unique values (like a set)
    unique_vals = random.sample(range(0, 100), length)
    single = unique_vals.pop()  # one value will appear once
    nums = unique_vals * 2      # all others appear twice
    nums.append(single)
    random.shuffle(nums)
    return nums, single

def main():
    nums, actual_single = generate_test_case()
    print("Input:", nums)
    print("Expected single number:", actual_single)
    print("Computed single number:", single_number(nums))

if __name__ == "__main__":
    main()
