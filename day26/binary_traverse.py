import random
from collections import deque

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def level_order(root):
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        result.append(level)

    return result

def tree_to_list(root):
    if not root:
        return []

    result = []
    queue = deque([root])
    while queue:
        node = queue.popleft()
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    
    # Trim trailing None values for cleaner output
    while result and result[-1] is None:
        result.pop()
    return result

def generate_random_tree(n_nodes):
    if n_nodes == 0:
        return None

    nodes = [TreeNode(random.randint(0, 99)) for _ in range(n_nodes)]
    for i in range(n_nodes):
        left_idx = 2 * i + 1
        right_idx = 2 * i + 2
        if left_idx < n_nodes:
            nodes[i].left = nodes[left_idx]
        if right_idx < n_nodes:
            nodes[i].right = nodes[right_idx]
    return nodes[0]

def main():
    n = random.randint(5, 10)
    root = generate_random_tree(n)
    print(f"Generated binary tree with {n} nodes:\n")
    print("Tree as level-order list (including None for missing children):")
    print(tree_to_list(root))
    print("\nLevel order traversal (grouped by level):")
    print(level_order(root))

if __name__ == "__main__":
    main()
