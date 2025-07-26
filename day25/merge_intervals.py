import random

def merge_intervals(intervals):
    if not intervals:
        return []

    # Sort by start time
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]

    for current in intervals[1:]:
        prev = merged[-1]
        if current[0] <= prev[1]:  # Overlap
            prev[1] = max(prev[1], current[1])
        else:
            merged.append(current)

    return merged

def generate_test_case():
    length = random.randint(5, 10)
    intervals = []
    for _ in range(length):
        start = random.randint(0, 20)
        end = start + random.randint(1, 10)
        intervals.append([start, end])
    random.shuffle(intervals)
    return intervals

def main():
    intervals = generate_test_case()
    print("Input:", intervals)
    merged = merge_intervals(intervals)
    print("Merged:", merged)

if __name__ == "__main__":
    main()
