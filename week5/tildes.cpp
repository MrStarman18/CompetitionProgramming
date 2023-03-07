//Notes on Union Find Disjoint Sets, which are used in Week 5 problems
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// required parallel arrays
vector<int> p; // parent
vector<int> r; // rank, required for efficiency

vector<int> s; // size (or other aggregate property)
int sets;

void init(int N) {
    p.assign(N,0);  //initialization, like p[N] = 0;
    iota(begin(p),end(p),0);
    r.assign(N,0);

    s.assign(N,1);  // optional
    sets = N;       // optional
}

int findSet(int i) { return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;}

void join(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x == y) return;
    if (r[x] > r[y]) swap(x, y);  // union by rank
    p[x] = y;
    if (r[x] == r[y]) ++r[y];     // union by rank
    s[y] += s[x];   // optional: update aggregate property. This is size
    --sets;
}

int sizeOfSet(int i)    { return s[findSet(i)]; }   // optional

int main() {
    int n, q, x, y;
    char operation;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++)
    {
        cin >> operation;
        if (operation == 't')
        {
           cin >> x >> y;
            join(x,y);
        }
        else   
        {    
            cin >> x;
            cout << sizeOfSet(x) << endl;
        }
    }
}