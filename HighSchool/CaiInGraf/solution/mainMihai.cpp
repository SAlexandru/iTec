#include <iostream>
#include <cstdio>

using namespace std;
string dict[1001];
int G[1001][1001];
int n,m;

void solve() {
    int n, m, from, x, y;
    cin >> n >> m >> from;

    for (int i=1;i<=n;i++) {G[i][0] = 0;}

    while(m > 0) {
        cin >> x >> y;
        G[x][0] ++;
        G[y][0] ++;
        G[x][G[x][0]] = y;
        G[y][G[y][0]] = x;
        m--;
    }


    int q[1001];
    int dist[1001];
    //int parent[1001];
    //int parent[1001];
    for (int i=1;i<1001;i++) dist[i] = -1;
    int head=0,tail=0;
    q[tail]=from;
    dist[from] = 0;
    while(!(head > tail)) {
        int current = q[head];
        for (int i=1;i<=G[current][0]; i++) {
            if(dist[G[current][i]] == -1) {
                q[++tail] = G[current][i];
                dist[G[current][i]] = dist[current] + 1;
                //parent[G[current][i]] = current;
            }
        }
        head++;
    }
    for (int i=1; i<=n;i++)
        cout << dist[i] << " ";
    cout << "\n";

}

int main() {
    char* in[] =  {"input1.in", "input2.in", "input3.in", "input4.in", "input5.in", "input6.in", "input7.in", "input8.in", "input9.in", "input10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};

    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solve();
    }
    return 0;

}
