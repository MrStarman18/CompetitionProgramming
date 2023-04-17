#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long n;
vector<long> w;
long globalgoal;
struct goalCoin {
    long coins;
    long goal;
    long callcoins;
};

goalCoin best;
goalCoin cache[200][20010];

void checkbest(goalCoin c) {
    if(c.goal > 0)
        return;
    if(abs(c.goal) < abs(best.goal) || (c.goal == best.goal && c.coins < best.coins)) {
        // cout << "new best goal: " << c.goal << " new coins: " << c.coins << endl;
        best = c;
    }
    return;
}

goalCoin coinCheck(long index, long goal, long coins)
{
    goalCoin gc;
    // cout << " g" << goal << " c" << coins << endl;
    gc.goal = goal;
    gc.coins = coins;
    goalCoin returnGoal = gc;
    if (index != n && goal > 0) {
        goalCoin currOff, currOn;
        if(cache[index+1][goal+10000].goal == -99999999 || cache[index+1][goal+10000].callcoins > gc.coins)
            currOff = coinCheck(index+1, goal, coins);
        else
            currOff = cache[index+1][goal+10000];
        if(cache[index+1][goal-w[index]+10000].goal == -99999999 || cache[index+1][goal-w[index]+10000].callcoins > gc.coins)
            currOn = coinCheck(index+1, goal-w[index], coins+1);
        else
            currOn = cache[index+1][goal-w[index]+10000];

        if ((currOff.goal < currOn.goal || globalgoal - currOn.goal < globalgoal) && currOff.goal >= 0) //should return smallest goal
            returnGoal = currOff;
        else
            returnGoal = currOn;
        checkbest(currOn);
        checkbest(currOff);

        if(currOff.goal == currOn.goal){
            if(currOff.coins < currOn.coins) {
                returnGoal = currOff;
            }
            else{
                returnGoal = currOn;
            }
        }
    }
    checkbest(gc); //redundant
    // cout << " return: " << returnGoal << endl;
    // if(cache[index][goal+10000].goal == -99999999 || cache[index][goal+10000].coins > returnGoal.coins)
    //     cache[index][goal+10000] = returnGoal;
    // return returnGoal;
    returnGoal.callcoins = coins;
    return cache[index][goal+10000] = returnGoal;

}

int main()
{
    long tests;
    cin >> tests;
    for(long i=0; i< tests; i++) {
        best.coins = 100000;
        best.goal = -99999999;
        w.clear();
        cin >> globalgoal >> n;
        for (long i = 0; i < n; ++i)
        {
            long mid;
            cin >> mid;
            w.push_back(mid);
        }

        for (long i = 0; i < 101; i++) {
            for (long j = 0; j < 20005; j++) {
                    cache[i][j].goal = -99999999;
                    cache[i][j].coins = 99999999;
                    cache[i][j].callcoins = 99999999;
            }
        }
        goalCoin t = coinCheck(0, globalgoal, 0);

        //cout << endl << t << endl;
        cout << globalgoal - best.goal << " " << best.coins << endl;
    }
}