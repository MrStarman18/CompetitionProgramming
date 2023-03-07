#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// required parallel arrays for UFDS
vector<int> p; // parent
vector<int> r; // rank, required for efficiency

void init(int N) {
    p.assign(N+1,0);  //initialization, like p[N] = 0;
    iota(begin(p),end(p),0);
    r.assign(N+1,0);
}

//If not in the root of the set/tree, go up 1 node and call again.
//Sets named after their root.
int findSet(int i) { return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;}

void join(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x == y) return;
    if (r[x] > r[y]) swap(x, y);  // union by rank
    p[x] = y;
    if (r[x] == r[y]) ++r[y];     // union by rank
}

bool isSameSet(int i,int j) { return findSet(i)==findSet(j); }  // optional

int main()
{
    int n, k, x, y;
    bool check = true;
    cin >> n >> k;
    init(n);
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        //scanf("%i", &x);
        //scanf("%i", &y);
        join(x, y);
    }
    for (int i = n; i > 0; i--)
    {
        if (isSameSet(i, n-i+1) == false)
        {
            check = false;
            break;
        }   
    }
    
    if(check)
        cout << "Yes\n";
    else   
        cout << "No\n";
}
