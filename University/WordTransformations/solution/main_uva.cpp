#include <queue>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using namespace std;

int distance(const string& s, const  string& w) {
    if (s.size() != w.size()) return -1;
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        count += s[i] != w[i];
    }

    return count;
}

int findPath(unordered_map<string, vector<string>>& G, const string& s, const string& p) {
    queue<string> q; 
    unordered_map<string, int> dist;

    dist[s] = 0;

    for (q.push(s); !q.empty(); q.pop()) {
        const string& n = q.front();
        const int d = dist[n];
        
        for (const auto& v: G[n]) {
            if (dist.find(v) == dist.end()) {
              dist[v] = d + 1;
              q.push(v);
            }
        }

        if (dist.find(p) != dist.end()) return dist[p];
    }

    return -1;
}

void solve() {
    unordered_map<string, vector<string>> G;
    
    for (string word; cin >> word && word != "*"; ) {
        for (const auto& p: G) {
            if (distance(p.first, word) == 1) {
              G[word].push_back(p.first);
              G[p.first].push_back(word);
            }
        }
        G[word];
    }

    cin.ignore();

    for (string line; getline(cin, line) && line != "";) {
       stringstream ss{line};
       string start, end;

       ss >> start >> end;

       cout << start << ' ' << end << ' ' << findPath(G, start, end) << '\n';
    }
}

int main() {
    int N;
    string line;

    cin >> N;
    getline(cin, line);
    while (N--) {
        solve();
        if (N) cout << "\n";
    }

    return 0;
}
