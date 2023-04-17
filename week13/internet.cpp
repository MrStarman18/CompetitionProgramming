//Week 12 Kattis problem Where's My Internet??
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

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
int findSet(int i) {return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;}

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

int main()
{
    int numHouses, numCables;
    cin >> numHouses >> numCables;
    init(numHouses+1);
    int x, y;
    for(int i = 0; i < numCables; i++)  //store all house relationships as UFDS
    {
        cin >> x >> y;
        join(x,y);
    }
    //final step
    if (sizeOfSet(1) == numHouses)  //All houses in same set as House 1
        cout << "Connected\n";
    else
    {
        for (int i = 2; i <= numHouses; i++)    //Check which houses aren't in House 1 set
        {
            if (!isSameSet(1, i))
                cout << i << endl;
        }
    }
}