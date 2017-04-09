#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define from first
#define to second

using namespace std;

typedef pair<int, int> Interval;

int getMaxOverlapping(const vector<Interval>& intervals) {
    int maxValue = 0;
    for (const auto& i : intervals) {
        maxValue = max(maxValue, max(i.from, i.to));
    }
    auto overlapping = vector<int>(maxValue + 1, 0);
    for (const auto& i : intervals) {
        overlapping[i.from]++;
        overlapping[i.to + 1]--;
    }
    int maxOverlapping = overlapping[0];
    for (int i = 1; i <= maxValue; i++) {
        overlapping[i] += overlapping[i - 1];
        maxOverlapping = max(maxOverlapping, overlapping[i]);
    }
    return maxOverlapping;
}

vector<Interval> normalize(const vector<Interval>& intervals) {
    auto values = vector<int>();
    for (const auto& i : intervals) {
        values.push_back(i.from);
        values.push_back(i.to);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    auto normalizedValues = unordered_map<int, int>();
    for (int i = 0; i < int(values.size()); i++) {
        normalizedValues[values[i]] = i;
    }
    auto normalizedIntervals = vector<Interval>();
    for (const auto& i : intervals) {
        normalizedIntervals.push_back(Interval(
                    normalizedValues[i.from],
                    normalizedValues[i.to]));
    }
    return normalizedIntervals;
}

vector<Interval> readIntervals() {
    int n;
    cin >> n;
    auto intervals = vector<Interval>(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].from >> intervals[i].to;
        intervals[i].to--;
    }
    return intervals;
}

int main() {
    const auto intervals = normalize(readIntervals());
    const int maxOverlapping = getMaxOverlapping(intervals);
    cout << maxOverlapping << "\n";
    return 0;
}
