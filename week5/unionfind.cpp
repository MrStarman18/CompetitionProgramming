#include <iostream>
#include <vector>
#include <numeric>
#include <stdio.h>
using namespace std;

vector<int> p; // parent
vector<int> r; // rank, required for efficiency


void init(int N) {
    p.assign(N,0);  //initialization, like p[N] = 0;
    iota(begin(p),end(p),0);
    r.assign(N,0);

}

int findSet(int i) { return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;}

void join(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x == y) return;
    if (r[x] > r[y]) swap(x, y);  // union by rank
    p[x] = y;
    if (r[x] == r[y]) ++r[y];     // union by rank
}

void isSameSet(int i,int j) { 
    if (findSet(i)==findSet(j)) 
        cout << "yes\n";
    else 
        cout << "no\n";
}

int main() {
    int n, q, x, y;
    char operation;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++)
    {
        scanf("%s", &operation);
        scanf("%i", &x);
        scanf("%i", &y);
        if (operation == '?')
            isSameSet(x, y);
        else   
            join(x, y);
    }
}