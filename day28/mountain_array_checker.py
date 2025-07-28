def is_mountain_array(arr):
    print("Input array:", arr)
    
    n = len(arr)
    if n < 3:
        return False

    i = 0

    # Ascend
    while i + 1 < n and arr[i] < arr[i + 1]:
        i += 1

    # Peak can't be first or last
    if i == 0 or i == n - 1:
        return False

    # Descend
    while i + 1 < n and arr[i] > arr[i + 1]:
        i += 1

    return i == n - 1

# Example usage
examples = [
    [0, 3, 2, 1],
    [2, 1],
    [3, 5, 5],
    [0, 1, 2, 3, 2, 1, 0]
]

for ex in examples:
    print("Is mountain:", is_mountain_array(ex))
    print("---")
