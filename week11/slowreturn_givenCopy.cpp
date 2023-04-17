//Week 11 Athene problem Slowest Return
//"Partial solution, but it is really slow"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int steps[1000];

vector<int> currSlowestPath;
vector<int> slowestPath;

// returns length of slowest path, ending at N
int _slowest(int n, int prevStep)   //Also updates the currSlowestPath to store this path for later use.
{
    if (n == 0)
        return 0;
 
    int max = 1;
    for (int i=0; i<n; i++)                             //iterate through steps[] from left to right
        if (steps[i] > steps[n]) {                      //if step is above the nth step(?), was in given
            int s = _slowest(i,steps[i]) + 1;
            if (s >= max && steps[i] < prevStep) {      //if this path is longer than max(?) and step is below previous step.
                max = s;
                if (find(currSlowestPath.begin(), currSlowestPath.end(), steps[i]) == currSlowestPath.end())   //if step not already in path
                    currSlowestPath.push_back(steps[i]);
            }
        }
    
    return max;
}

int slowest(int n)
{
    int max = 0;
    for (int i=0; i<=n; i++) {
        int s = _slowest(i,steps[i]);
        if (s >= max) {                         //if the computed path is slower than the saved slowest overall,
            max = s;
            slowestPath = currSlowestPath;      //save it instead.
        }
    }
    return max;
}

int main()
{
    int n = 0;
    int x;
    while (cin >> x)
        steps[n++] = x;
    cout << n << " " << slowest(n) << endl << endl;
    for (auto i = slowestPath.begin(); i != slowestPath.end(); ++i)
        cout << *i << " ";
    cout << endl;
}
