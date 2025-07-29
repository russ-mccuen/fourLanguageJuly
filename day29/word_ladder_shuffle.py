from collections import deque

def word_ladder(start, end, dictionary):
    print("Start word:", start)
    print("End word:", end)
    print("Dictionary:", dictionary)
    print()

    word_set = set(dictionary)
    if end not in word_set:
        print("End word not in dictionary.")
        return []

    queue = deque([[start]])
    visited = set([start])

    while queue:
        path = queue.popleft()
        current = path[-1]
        print("Current path:", path)

        if current == end:
            return path

        for i in range(len(current)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = current[:i] + c + current[i+1:]
                if next_word in word_set and next_word not in visited:
                    visited.add(next_word)
                    queue.append(path + [next_word])

    print("No transformation path found.")
    return []

# Example usage
start = "hit"
end = "cog"
dictionary = ["hot", "dot", "dog", "lot", "log", "cog"]

result = word_ladder(start, end, dictionary)
print("\nFinal transformation path:")
print(result)
