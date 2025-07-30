# defaultdict lets us automatically create a set for each key without needing to check if the key exists.
# deque is a double-ended queue optimized for popping from the left, perfect for BFS.
from collections import defaultdict, deque

def alienOrder(words):
    # Step 1: Build graph and in-degree map
    # Each character will have an entry in in_degree initialized to 0
    graph = defaultdict(set)
    in_degree = {char: 0 for word in words for char in word}

    print("Initial in-degree map:", in_degree)

    # Compare adjacent words to build the graph
    for i in range(len(words) - 1):
        first, second = words[i], words[i+1]
        for a, b in zip(first, second):
            if a != b:
                # Only add edge if it's not already present
                if b not in graph[a]:
                    graph[a].add(b)
                    in_degree[b] += 1
                break
        else:
            # Handle invalid prefix case (e.g., "abc" before "ab")
            if len(second) < len(first):
                return ""

    # Debug print of the graph
    print("Graph (edges):")
    for k, v in graph.items():
        print(f"  {k} → {v}")
    print("Updated in-degree map after edges:", in_degree)

    # Step 2: Topological sort using BFS
    # Start with all nodes that have 0 in-degree
    queue = deque([c for c in in_degree if in_degree[c] == 0])
    result = []

    print("Starting BFS with queue:", list(queue))

    while queue:
        c = queue.popleft()
        result.append(c)
        print(f"Visiting: {c}")
        for neighbor in graph[c]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    print("Final result list:", result)

    # If not all letters are in result, a cycle was detected
    if len(result) < len(in_degree):
        return ""

    return "".join(result)

# Example usage
words = ["wrt", "wrf", "er", "ett", "rftt"]
print("Input words:", words)
print("Alien dictionary order:", alienOrder(words))
