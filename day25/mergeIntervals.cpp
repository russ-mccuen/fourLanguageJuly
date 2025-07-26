#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using Interval = std::pair<int, int>;

std::vector<Interval> mergeIntervals(std::vector<Interval>& intervals) {
    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end());

    std::vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        Interval& last = merged.back();
        if (intervals[i].first <= last.second) {
            last.second = std::max(last.second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

std::vector<Interval> generateTestCase() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int n = std::rand() % 6 + 5; // 5–10 intervals
    std::vector<Interval> intervals;
    for (int i = 0; i < n; ++i) {
        int start = std::rand() % 21;
        int end = start + std::rand() % 10 + 1;
        intervals.emplace_back(start, end);
    }
    std::random_shuffle(intervals.begin(), intervals.end());
    return intervals;
}

void printIntervals(const std::vector<Interval>& intervals) {
    for (const auto& [start, end] : intervals) {
        std::cout << "[" << start << "," << end << "] ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<Interval> intervals = generateTestCase();

    std::cout << "Input: ";
    printIntervals(intervals);

    std::vector<Interval> merged = mergeIntervals(intervals);

    std::cout << "Merged: ";
    printIntervals(merged);

    return 0;
}
