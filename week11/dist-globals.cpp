//Class example Dynamic Programming problem, 3/27/2023
//Step 2: "Programming contest solution" because of global variable use.
//This version treats a and b as const variables (variables that are never changed).

#include <iostream>
#include <algorithm>
using namespace std;

string a,b;

// compute Levenshtein distance for globals a & b
int dist(int i,int j)
{
    // a is empty, insert whatever is left in b
    if (!a[i]) return b.length()-j;

    // b is empty, insert whatever is left in a
    if (!b[j]) return a.length()-i;

    // they match, shrink the problem
    if (a[i] == b[j]) return dist(i+1,j+1);

    // try all possible edits
    return 1 + min({
        dist(i,j+1),    // insert at a[i] whatever is in b[j]
        dist(i+1,j),    // remove a[i]
        dist(i+1,j+1)   // replace a[i] with b[j]
    });
}

int main(int argc,char *argv[]) 
{
    a = argv[1];
    b = argv[2];
    cout << dist(0,0) << "\n";
}
