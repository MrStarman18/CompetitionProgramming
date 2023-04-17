#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int steps[1000];

// returns length of slowest path, ending at N
int _slowest(int n, int prevStep, vector<int>& slowestPath, vector<int>& currSlowestPath)   //Also updates the currSlowestPath to store this path for later use.
{
    currSlowestPath.clear();
    if (n == 0)
        return 0;
 
    int max = 1;
    for (int i=0; i<n; i++)                             //iterate through steps[] from left to right
        if (steps[i] > steps[n]) {                      //if step is above the nth step(?), was in given
            int s = _slowest(i,steps[i], slowestPath, currSlowestPath) + 1;
            if (s >= max && steps[i] < prevStep) {
                max = s;
                if (find(currSlowestPath.begin(), currSlowestPath.end(), steps[i]) == currSlowestPath.end()) {
                    currSlowestPath.clear();   // Clear currSlowestPath before adding a new element
                    currSlowestPath.push_back(steps[i]);
                    currSlowestPath.insert(currSlowestPath.end(), slowestPath.begin(), slowestPath.end());  // Add the previous slowestPath to currSlowestPath
                    slowestPath = currSlowestPath;  // Update slowestPath with the new path
                }
            }
        }
    
    return max;
}

int slowest(int n)
{
    int max = 0;
    vector<int> currSlowestPath;
    vector<int> slowestPath;
    slowestPath.clear();
    for (int i=0; i<=n; i++) {
        currSlowestPath.clear();
        int s = _slowest(i,steps[i], slowestPath, currSlowestPath);
        if (s >= max) {                         //if the computed path is slower than the saved slowest overall,
            max = s;
        }
    }

    for (auto i = slowestPath.begin(); i != slowestPath.end(); ++i)
        cout << *i << " ";

    return max;
}

int main()
{
    int n = 0;
    int x;
    while (cin >> x)
        steps[n++] = x;
    cout << n << " " << slowest(n) << endl << endl;
    cout << endl;
}
