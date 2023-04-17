#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> w;
vector<bool> weightOn;

//"split in half"
//for each weight, find compliment weight closest to 1000-weight
int weightCheck(int index, int goal)
{
    //cout << "index: " << index << " goal: " << goal << endl;
    if (index == n) return goal;

    int currOff = weightCheck(index+1, goal);       //goal w currentWeight off
    int currOn = weightCheck(index+1, goal-w[index]);   //goal w currentWeight on

    int t;
    if (abs(currOff) < abs(currOn)) //should return smallest goal
       t = currOff;
    else
        t = currOn;

    //cout << "t: " << t << endl;
    return t;

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int mid;
        cin >> mid;
        w.push_back(mid);
        weightOn.push_back(0);
    }
    int t = weightCheck(0, 1000);
    //cout << endl << t << endl;
    cout << 1000 - t << endl;
}