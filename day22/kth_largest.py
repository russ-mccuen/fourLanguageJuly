import random
import heapq    # provides implementation of heapq algorithm

def kth_largest(nums, k):
    return heapq.nlargest(k, nums)[-1]

def generate_test_case():
    length = random.randint(10, 30)
    nums = [random.randint(0, 100) for _ in range(length)]
    k = random.randint(1, length)
    return nums, k

def main():
    nums, k = generate_test_case()
    print("Input:", nums)
    print("k:", k)
    print(f"{k}th largest element:", kth_largest(nums, k))

if __name__ == "__main__":
    main()
