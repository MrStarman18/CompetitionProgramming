//Class example Dynamic Programming problem, 3/27/2023
//Step 4:
//
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

string a,b;
int cache[100][100];
const int M=999999999;  //Functionally infinity

int main(int argc,char *argv[]) 
{
    a = argv[1];
    b = argv[2];

    for (int i=a.length(); i>=0; i--)
        for (int j=b.length(); j>=0; j--)
            if (!a[i])              //a[i] == 0, a is empty
                cache[i][j] = b.length()-j;
            else if (!b[i])         //b[j] == 0, b is empty
                cache[i][j] = a.length()-i;
            else if (a[i]==b[j])    //they match, shrink the problem
                cache[i][j] = cache[i+1][j+1];
            else                    //try all possible edits
                cache[i][j] = 1 + min({
                    j<b.length() ? cache[i][j+1] : M,
                    i<a.length() ? cache[i+1][j] : M,
                    i<a.length() && j<b.length() ? cache[i+1][j+1] : M
                });

    cout << cache[0][0] << "\n";

    for (int i=0; i<=a.length(); i++) {
        for (int j=0; j<=b.length(); j++)
            cout << setw(3) << cache[i][j];
        cout << "\n";
    }
}
