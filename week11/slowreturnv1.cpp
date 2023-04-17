//Week 11 Athene problem Slowest Return
#include <iostream>
#include <vector>
using namespace std;
//This solution was complicated and didn't work. Restarting for the next version.

int n = 0;          //number of steps
int steps[1000];    //the steps' heights
struct path
{
    vector<int> stepPath;
    int pathLength = 0;
};
path slowPath;
vector<vector<path>> cache; //stores each path. indexed by firstStep, index

//calculate routes, given the path's first step, the current step, and the # path this is that starts with same first step
path slowest(int firstStep, int i, int index)
{
    if (i = n)
        return slowPath;
    else
    {
        (cache[firstStep][index].stepPath).push_back(steps[i]); //add current step to current path
        cache[firstStep][index].pathLength++;                   //increment current path's length
    }   

    for (int loop = i+1; loop < n; ++loop)              //for every step,
    {
        if (steps[loop] > 0 && steps[loop] < steps[i])  //for each subsequent step that's < current step
            slowest(firstStep, loop, ++index);              //check paths from that step
    }           
    if (slowPath.pathLength < cache[firstStep][index].pathLength)   //Compare current Path to current Slowest Path
        {
            slowPath = cache[firstStep][index];
            cout << slowPath.pathLength;
            cout << endl;

        } 
    return slowPath;                                                //Return the slower of the two
}

int main()
{
    int x;
    while (cin >> x)
        steps[n++] = x;
    path best = slowest(steps[0], steps[0], 0);

    //iterate through best and print it
    for (auto i = best.stepPath.begin(); i != best.stepPath.end(); ++i)
        cout << *i << " ";
}
