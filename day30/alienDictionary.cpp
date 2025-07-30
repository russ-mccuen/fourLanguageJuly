#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

string alienOrder(const vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> inDegree;

    // Initialize in-degree for all unique characters
    for (const string& word : words) {
        for (char c : word) {
            inDegree[c] = 0;
        }
    }

    // Build graph edges and update in-degrees
    for (size_t i = 0; i < words.size() - 1; ++i) {
        string first = words[i];
        string second = words[i + 1];
        int len = min(first.size(), second.size());

        if (first.size() > second.size() && first.substr(0, len) == second) {
            return "";
        }

        for (int j = 0; j < len; ++j) {
            char a = first[j];
            char b = second[j];
            if (a != b) {
                if (!graph[a].count(b)) {
                    graph[a].insert(b);
                    inDegree[b]++;
                }
                break;
            }
        }
    }

    // Topological sort (BFS)
    queue<char> q;
    for (const auto& [c, degree] : inDegree) {
        if (degree == 0) q.push(c);
    }

    string order;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        order += c;
        for (char neighbor : graph[c]) {
            if (--inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    if (order.length() != inDegree.size()) return "";

    return order;
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    
    cout << "Input words:\n";
    for (const string& word : words) {
        cout << word << "\n";
    }

    string order = alienOrder(words);

    cout << "\nInferred alien dictionary order:\n";
    if (order.empty()) {
        cout << "(Invalid dictionary — cycle or prefix conflict detected)\n";
    } else {
        cout << order << "\n";
    }

    return 0;
}
