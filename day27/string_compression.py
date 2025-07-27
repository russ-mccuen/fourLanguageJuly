def compress_string(s: str) -> str:
    if not s:
        print("Original: ''")
        print("Compressed: ''")
        return s

    compressed = []
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
        else:
            compressed.append(s[i - 1] + str(count))
            count = 1

    compressed.append(s[-1] + str(count))  # append last group
    result = ''.join(compressed)

    print(f"Original: {s}")
    print(f"Compressed: {result if len(result) < len(s) else s}")

    return result if len(result) < len(s) else s

# Example test
compress_string("aabcccccaaa")
compress_string("abc")
