//Week 14 Kattis problem A Feast for Cats
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{    //describes the distance between 2 cats
    int cat1;
    int cat2;
    int dist;
    friend bool operator< (edge const& lhs, edge const& rhs) {
        return lhs.dist > rhs.dist;
    }
    friend void operator <<(ostream &oss, edge const& e) {
        oss << e.cat1 << " " << e.cat2 << " " << e.dist << '\n';
    }
};
vector<edge> catGraph;  //Store distance between all cats
int milkTotal, numCats; //Store number of cats and total amount of milk

//solve first assuming that we carry all milk at once
    //prioritize lowest edge cost, if this path is > milkTotal we lose.
//then update for "serving a cat more milk than needed"
vector<int> MST(edge v)
{
    int milk = milkTotal;
    vector<int> V;
    priority_queue<edge> T;
    T.push({-1, 0, 0});
    int currCat = v.cat1;
    while(!T.empty())
    {
        //cout << "A\n";
        v = T.top();
        T.pop();

        if (!count(V.begin(), V.end(), v.cat2) && v.dist <= milk)  //Getting stuck at first edge?
            currCat = v.cat2;
        else if (!count(V.begin(), V.end(), v.cat1) && v.dist <= milk)
            currCat = v.cat1;
        else
            continue;
        //cout << "currCat: " << currCat << endl;

        //If we haven't visted this cat and we have enough milk to visit it
        if (!count(V.begin(), V.end(), currCat))
        {
            //formerly set "curCat = v.cat1" here
            V.push_back(currCat);    //We visit this cat,
            milk -= v.dist;         //and expend the milk to get there.
            //cout << v;
            //cout << "Milk: " << milk << endl;
            for (auto i = catGraph.begin(); i != catGraph.end(); i++)   //NEED TO: Speed up this for loop
            {   //add all connected cats to the to-do list.
                if ( ((*i).cat1 == currCat || (*i).cat2 == currCat) && v.dist <= milk)
                    T.push(*i);
            }
        }
        else    //we're visiting a cat we've already fed
            break;
            
    }
    return V;   //We need to know if all cats were visited successfully
}

int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 0; i < numCases; i++)  //for each test case
    {
        cin >> milkTotal >> numCats;
        catGraph.clear();
        int loop = (numCats*(numCats - 1)) / 2; //Used for cin loop
        for (int j = 0; j < loop; j++)
        {
            edge temp;
            cin >> temp.cat1 >> temp.cat2 >> temp.dist;
            catGraph.push_back(temp);
        }
        
        //compute cat traveral and output result
        vector<int> result = MST(catGraph[0]);
        bool can = true;
        for (int i = 0; i < numCats; i++)
        {
            //cout << count(result.begin(), result.end(), i) << " ";
            if(!count(result.begin(), result.end(), i))
            {
                can = false; 
                //break;
            }
        }
        //cout << endl;
        if (can)
            cout << "yes\n";
        else 
            cout << "no\n";
    }

}