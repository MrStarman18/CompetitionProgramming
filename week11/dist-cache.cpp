//Class example Dynamic Programming problem, 3/27/2023
//Step 3: Memoization ("leave a little note") or cache solution; previously 
//  computed answers are stored in cache.
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

string a,b;
int cache[100][100];    //cache's # of dimensions == dist's # of parameters.

// compute Levenshtein distance for globals a & b
int dist(int i,int j)
{
    if (cache[i][j] > 0) return cache[i][j];

    // a is empty, insert whatever is left in b
    if (!a[i]) return cache[i][j] = b.length()-j;   //returns value assigned to cache[i][j]

    // b is empty, insert whatever is left in a
    if (!b[j]) return cache[i][j] = a.length()-i;

    // they match, shrink the problem
    if (a[i] == b[j]) return cache[i][j] = dist(i+1,j+1);

    // try all possible edits
    return cache[i][j] = 1 + min({
        dist(i,j+1),    // insert at a[i] whatever is in b[j]
        dist(i+1,j),    // remove a[i]
        dist(i+1,j+1)   // replace a[i] with b[j]
    });
}

int main(int argc,char *argv[]) 
{
    a = argv[1];
    b = argv[2];

    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            cache[i][j] = -1;

    cout << dist(0,0) << "\n";

    for (int i=0; i<=a.length(); i++) {
        for (int j=0; j<=b.length(); j++)
            cout << setw(3) << cache[i][j];
        cout << "\n";
    }
}

/*

*/