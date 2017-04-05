#include <queue>
#include <array>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;

int iAbs(int x) { return x < 0 ? -x : x;}

void printTo(const string& filename, const unordered_map<string, vector<string>> & v) {
    ofstream out{filename + ".dot"};

    out << "strict graph {\n";
    out << "    graph [splines=true overlap=false layout=sfdp];\n";
//    out << "    node [shape=none];\n";
    for (const auto& x: v) {
        if (x.second.empty()) {
            out << x.first << "\n";
        }
        for (const auto& y: x.second) {
            out << x.first << " -- " << y << "\n";
        }
    }

    out << "}\n";

    out.close();
}



int distance(string s, string w) {
    if (s.size() == w.size()) {
      int count = 0;
      for (size_t i = 0; i < s.size(); ++i) {
          count += s[i] != w[i];
      }
      return count;
    }
    else if (iAbs(s.size() - w.size()) == 1) {
        if (w.size() > s.size()) swap(s, w);
        int count = 0;
        for (size_t i = 0, j = 0; i < s.size() && count <= 1; ++i) {
            if (s[i] != w[j]) {
                ++count;
            }
            else ++j;
        }

        return count;
    }
    else {
        return -1;
    }
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
    int N, M;
    unordered_map<string, vector<string>> G;
   
    cin >> N >> M;
    assert(1 <= N && N <= 1000);
    assert(1 <= M && M <= 1000);
    for (string word; N; --N) {
        cin >> word;
        assert(1 <= word.size() && word.size() <= 10);
        for(const auto& x: word) {
            assert(x >= 'a' && x <= 'z');
        }

        if (G.find(word) == G.end()) {
          G[word] = vector<string>(); 
          for (const auto& p: G) {
                if ( distance(p.first, word) == 1) {
                  G[word].push_back(p.first);
                  G[p.first].push_back(word);
                }
          }
        }

    }

    printTo("input", G);

    cin.ignore();
    for (string line; M; --M)  {
       getline(cin, line);

       stringstream ss{line};
       string start, end;

       ss >> start >> end;
       assert(1 <= start.size() && start.size() <= 10);
       assert(1 <= end.size() && end.size() <= 10);
        for(const auto& x: start) {
            assert(x >= 'a' && x <= 'z');
        }
        for(const auto& x: end) {
            assert(x >= 'a' && x <= 'z');
        }




       cout << start << ' ' << end << ' ' << findPath(G, start, end) << '\n';
    }
}

int main() {

    solve();

    return 0;
}
