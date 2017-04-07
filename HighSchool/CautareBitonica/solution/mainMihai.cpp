#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int nr[500002];

void findElement(int el, int pivotPos) {
    int from = 1, to = pivotPos, found1 = -1, found2 = -1;
    while(from <= to) {
        int mid = (from + to)/2;
        if(el == nr[mid]) {found1 = mid;break;}
        else if(el > nr[mid]) from = mid+1;
        else to = mid - 1;
    }

    from = pivotPos + 1; to = n;
    while(from <= to) {
        int mid = (from + to)/2;
        if(el == nr[mid]) {found2 = mid;break;}
        else if(el < nr[mid]) from = mid+1;
        else to = mid - 1;
    }

    if(found1 > 0 && found2 > 0) cout << found1-1 << " " << found2-1 << " \n";
    else if(found1 > 0 && found2 < 0) cout << found1-1 << " \n";
    else if(found1 < 0 && found2 > 0) cout << found2-1 << " \n";
    else cout <<"Number Not Found\n";
}

void solveProblem() {
    int a;
    cin >> n;
    int pivotPos;
    bool foundPivot;
    pivotPos = -1;
    foundPivot = false;

    for (int i=1;i<=n;i++) {
        cin >> nr[i];
        if(i >=2 && nr[i] < nr[i-1] && !foundPivot) {
            pivotPos = i-1; foundPivot = true;
        }
    }
    if(!foundPivot) {pivotPos = n;}

    cin >> m;
    for (int i=1;i<=m;i++) {
        cin >> a;
        findElement(a, pivotPos);
    }

}

int main()
{
    char* in[] =  {"input1.in", "input2.in", "input3.in", "input4.in", "input5.in", "input6.in", "input7.in", "input8.in", "input9.in", "input10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};

    for (int i=9;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solveProblem();
    }
    return 0;
}
