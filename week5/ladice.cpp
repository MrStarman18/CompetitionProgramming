//Notes on Union Find Disjoint items, which are used in Week 5 problems
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// required parallel arrays
vector<int> p; // parent
vector<int> r; // rank, required for efficiency

vector<int> s; // size (or other aggregate property)
vector<int> numItems;
int items;

void init(int N) {
    p.assign(N,0);  //initialization, like p[N] = 0;
    iota(begin(p),end(p),0);
    r.assign(N,0);

    s.assign(N,1);  // optional
    items = N;       // optional
}

int findSet(int i) { return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;}

void join(int i, int j) {
    
    int x = findSet(i);
    int y = findSet(j);
    numItems[y]++;
    if (x == y) return;
    if (r[x] > r[y]) swap(x, y);  // union by rank
    p[x] = y;
    if (r[x] == r[y]) ++r[y];     // union by rank
    s[y] += s[x];   // optional: update aggregate property. This is size
}

bool isSameSet(int i,int j) { return findSet(i)==findSet(j); }  // optional
int sizeOfSet(int i)        { return s[findSet(i)]; }           // optional

int main()
{
    int n, q, x, y;
    cin >> n >> q;
    init(q);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        join(x, y);
        
    }
}