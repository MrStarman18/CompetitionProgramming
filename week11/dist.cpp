//Class example Dynamic Programming problem, 3/27/2023
//Step 1
#include <iostream>
#include <algorithm>
using namespace std;

// compute Levenshtein distance between a & b
//This implementation is ~ O(3^N), or "really slow"
int dist(string a,string b)
{
    // a is empty, insert whatever is left in b
    if (a=="") return b.length();

    // b is empty, insert whatever is left in a
    if (b=="") return a.length();

    // first characters match, shrink the problem
    if (a[0] == b[0]) return dist(a.substr(1),b.substr(1));

    // try all possible edits, return the shortest distance
    return 1 + min({
        dist(a,b.substr(1)),            // insert at a[0] char in b[0]
        dist(a.substr(1),b),            // remove a[0]
        dist(a.substr(1),b.substr(1))   // replace a[0] with b[0]
    });
}

int main(int argc,char *argv[]) 
{
    cout << dist(argv[1],argv[2]) << "\n";
}

/* 
Levenshtein distance, or edit distance, refers to how many edits
    need to be made to convert one string into another.
Examples:
"abcdef" and "axcdeg" are 2 apart.
"abcidef" and "axcdeg" are 3 apart.

*/