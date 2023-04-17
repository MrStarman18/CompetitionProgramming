#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> w;
int cache[1001][2005];

//"split in half"
//for each weight, find compliment weight closest to 1000-weight
int weightCheck(int index, int goal)
{
    // cout << "index: " << index << " goal: " << goal << endl;
    int returnGoal = goal;
    if (index != n && goal >= 0) {
        int currOff, currOn;
        if(cache[index+1][goal+1000] == 1001)
            currOff = weightCheck(index+1, goal);       //goal w currentWeight off
        else
            currOff = cache[index+1][goal+1000];
        if(cache[index+1][goal-w[index]+1000] == 1001)
            currOn = weightCheck(index+1, goal-w[index]);       //goal w currentWeight off
        else
            currOn = cache[index+1][goal-w[index]+1000];

        if (abs(currOff) < abs(currOn)) //should return smallest goal
            returnGoal = currOff;
        else
            returnGoal = currOn;
    }
    // cout << " return: " << returnGoal << endl;
    return cache[index][goal+1000] = returnGoal;

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int mid;
        cin >> mid;
        w.push_back(mid);
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 2005; j++) {
            cache[i][j] = 1001;
        }
    }
    int t = weightCheck(0, 1000);
    //cout << endl << t << endl;
    cout << 1000 - t << endl;
}