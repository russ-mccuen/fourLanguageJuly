import random

def product_except_self(nums):
    n = len(nums)
    output = [1] * n

    # Prefix product pass
    prefix = 1
    for i in range(n):
        output[i] = prefix
        prefix *= nums[i]

    # Suffix product pass
    suffix = 1
    for i in reversed(range(n)):
        output[i] *= suffix
        suffix *= nums[i]

    return output

def generate_test_case():
    length = random.randint(5, 10)
    nums = [random.randint(1, 10) for _ in range(length)]
    return nums

def main():
    nums = generate_test_case()
    print("Input:", nums)
    print("Output:", product_except_self(nums))

if __name__ == "__main__":
    main()
