#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> w;
int total = 0;                  //answer to be returned
int cache[1001][40001]{0};   //stores 0 or 1 based on if value has been computed already

//"split in half"
//for each fruit, compute all possible baskets using that fruit
int weightCheck(int index, int goal)
{
    int score = 0;
    if (index != n) {
        cout << "index: " << index << " goal: " << goal << endl;
       
        int currOff, currOn;
        if(cache[index][goal] == 0)
        {
            currOff = weightCheck(index+1, goal);       //total w currentWeight off
            //cache[index][goal] = goal;
        }
        else
        {    currOff = cache[index][goal];}
        if(cache[index][goal+w[index]] == 0)
        {
            currOn = weightCheck(index+1, goal+w[index]) + w[index];       //total w currentWeight off
            //cache[index][goal] = goal+w[index];
        }
        else
        {   currOn = cache[index][goal+w[index]];}

        if (currOff >= 200) //should add to total if >= 200
        {
            total += currOff;
            score += currOff;
            cout << " total: " << total << endl;
        }    
        if (currOn >= 200)  //Addition in these functions is off. Need to return the total weight at a given fruit
        {    
            total += currOn;  
            score += currOn;          
            cout << " total: " << total << endl;
        }
    }
    //cout << " return\n";
    return cache[index][goal] = score;

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

    // for (int i = 0; i < 1001; i++) {
    //     for (int j = 0; j < 2005; j++) {
    //         cache[i][j] = 1001;
    //     }
    // }
    weightCheck(0, 0);
    //cout << endl << t << endl;
    cout << total << endl;
}