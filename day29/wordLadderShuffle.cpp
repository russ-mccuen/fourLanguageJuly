#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

bool oneLetterDiff(const string& a, const string& b) {
    int diff = 0;
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) ++diff;
        if (diff > 1) return false;
    }
    return diff == 1;
}

vector<string> wordLadder(const string& start, const string& end, const vector<string>& dict) {
    cout << "Start word: " << start << endl;
    cout << "End word: " << end << endl;
    cout << "Dictionary: ";
    for (const string& w : dict) cout << w << " ";
    cout << "\n\n";

    unordered_set<string> wordSet(dict.begin(), dict.end());
    if (!wordSet.count(end)) {
        cout << "End word not in dictionary.\n";
        return {};
    }

    queue<vector<string>> q;
    q.push({start});
    unordered_set<string> visited;
    visited.insert(start);

    while (!q.empty()) {
        auto path = q.front(); q.pop();
        string current = path.back();
        cout << "Current path: ";
        for (const string& word : path) cout << word << " ";
        cout << endl;

        if (current == end) return path;

        for (const string& word : wordSet) {
            if (visited.count(word) == 0 && oneLetterDiff(current, word)) {
                visited.insert(word);
                auto newPath = path;
                newPath.push_back(word);
                q.push(newPath);
            }
        }
    }

    cout << "No transformation path found.\n";
    return {};
}

int main() {
    string start = "hit";
    string end = "cog";
    vector<string> dictionary = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<string> result = wordLadder(start, end, dictionary);

    cout << "\nFinal transformation path:\n";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
}
