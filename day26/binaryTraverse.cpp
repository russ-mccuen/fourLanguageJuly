#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

// C++ 11 compliant

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int v) : val(v) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }

    return result;
}

// Using -1 as a sentinel value for null (assuming random values are always 0–99)
std::vector<int> treeToList(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1);  // sentinel for null
        }
    }

    // Trim trailing -1s
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }

    return result;
}

TreeNode* generateRandomTree(int n) {
    if (n == 0) return nullptr;

    std::vector<TreeNode*> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.push_back(new TreeNode(rand() % 100));
    }

    for (int i = 0; i < n; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n) nodes[i]->left = nodes[left];
        if (right < n) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int n = std::rand() % 6 + 5; // 5–10 nodes
    TreeNode* root = generateRandomTree(n);

    std::cout << "Generated binary tree with " << n << " nodes:\n";
    std::cout << "Tree as level-order list (-1 = null):\n";
    std::vector<int> flat = treeToList(root);
    for (int val : flat) {
        std::cout << (val == -1 ? "null" : std::to_string(val)) << " ";
    }

    std::cout << "\n\nLevel order traversal (grouped by level):\n";
    std::vector<std::vector<int>> levels = levelOrder(root);
    for (const auto& level : levels) {
        std::cout << "[ ";
        for (int val : level) std::cout << val << " ";
        std::cout << "]\n";
    }

    return 0;
}
