#include <iostream>
#include <stdio.h>

using namespace std;

string dict[1001];
int G[1001][1001];
int n,m;


bool canTranslate(string a, string b) {
    int letterDiff = 0;
    if(a.length() == b.length()) {
        for (int i=0;i<a.length();i++) {
            if(a[i] != b[i]) {
                letterDiff ++;
            }
        }
        return letterDiff == 1;
    }
    if(a.length() < b.length()) {
        // larger string is kept in a
        string aux = a; a=b; b=aux;
    }
    if(a.length() == b.length() + 1) {
        int j=0;
        for (int i=0; i<a.length(); i++) {
            if(a[i] != b[j]) {
                letterDiff ++;
            } else j++;
        }
        return letterDiff == 1;

    } else return false;
}

void solveItemized(string a, string b, int from, int to) {
    int q[1001];
    int dist[1001];
    //int parent[1001];
    for (int i=0;i<1001;i++) dist[i] = -1;
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
    cout << a << " " << b << " " << dist[to] << "\n";
}


void solve() {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> dict[i];
    for (int i=0;i<n;i++) {G[i][0] = 0;}
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j < n ;j++) {
            if(canTranslate(dict[i], dict[j])) {
                G[i][0] ++;
                G[j][0] ++;
                G[i][G[i][0]] = j;
                G[j][G[j][0]] = i;
            }
        }
    }

    string a,b;
    int indexA, indexB;
    for (int i=0;i<m;i++) {
        cin >> a >> b;
        indexA = -1; indexB = -1;
        for (int j=0;j < n; j++) {
            if(dict[j] == a) indexA = j;
            if(dict[j] == b) indexB = j;
        }
        if(indexA == -1 || indexB==-1)
            cout << a << " " << b << " " << -1 << "\n";
        else solveItemized(a, b, indexA, indexB);
    }
}

int main()
{

    char* in[] =  {"input1.in", "input2.in", "input3.in", "input4.in", "input5.in", "input6.in", "input7.in", "input8.in", "input9.in", "input10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};
    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solve();
    }

    //freopen("input3.in", "r",stdin);
    //freopen("3.ot","w",stdout);
    //solve();
    return 0;
}
