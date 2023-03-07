//Notes on Union Find Disjoint Sets, which are used in Week 5 problems
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// required parallel arrays
vector<int> p; // parent
vector<int> r; // rank, required for efficiency

// optional
vector<int> s; // size (or other aggregate property)
int sets;

void init(int N) {
    p.assign(N,0);  //initialization, like p[N] = 0;
    iota(begin(p),end(p),0);
    r.assign(N,0);

    s.assign(N,1);  // optional
    sets = N;       // optional
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
    s[y] += s[x];   // optional: update aggregate property. This is size
    --sets;
}

bool isSameSet(int i,int j) { return findSet(i)==findSet(j); }  // optional
int sizeOfSet(int i)        { return s[findSet(i)]; }           // optional

/*Notes:
Its only operations are:
    Create N groups, each with a unique element
    Join two groups (given an element in each)

However, it can answer the following questions about the groups:
    Which group is an element in?
    Are two elements in the same group?
    How many (disjoint) groups exist?
 
In addition, group aggregate properties can be maintained. These include things like:
    min/max element
    sum/total value of elements
    size of group

All operations are O(1) for N less than a few billion, thus for all contest data sets.

*/