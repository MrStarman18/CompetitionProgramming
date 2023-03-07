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
int sizeOfSet(int i)        {return s[findSet(i)]; }           // optional

bool canMake(int ing, vector<int> &iList, int &numIng)
{
    int numHits = 0;

    if (sizeOfSet(ing) == 1)
    {
        return true;
    }    
    //this set contains elements not needed for current potion)
    for(int i = 0; i < numIng; i++)
    {
        if (isSameSet(iList[i], ing))
            numHits++;
        if(numHits == sizeOfSet(ing))
            return true;
    } 

    return false;
}
int main()
{
    int n, numIng = 0, total = 0, middleMan;
    init(500000);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &numIng);
        std::vector <int> iList (numIng+1);
        bool makeable = true;
        for(int j = 0; j < numIng; j++) //read in list
        {
            scanf("%i", &middleMan);
            iList[j] = middleMan;
        }
        for(int j = 0; j < numIng; j++) //check if current potion is makeable
        {
            if(canMake(iList[j], iList, numIng) == false)
            {
                makeable = false;
                break;
            }
        }

        if (makeable)   //if makeable, make it
        {
            for(int j = 0; j < numIng - 1; j++) 
            {
                join(iList[j], iList[j+1]);
            }
            total++;
        }           
    }
    cout << total << endl;
}