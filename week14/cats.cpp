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
        oss << e.cat1 << " " << e.cat2 << " " << e.dist << endl;
    }
};
vector<vector<edge>> catGraph;  //Store distance between all cats
int milkTotal, numCats; //Store number of cats and total amount of milk

vector<int> MST()
{
    int milk = milkTotal;
    vector<int> V;
    priority_queue<edge> T;
    T.push({-1, 0, 0});
    int currCat;
    edge v;
    while(!T.empty())
    {
        // cout << "A\n";
        v = T.top();
        T.pop();
        // cout << "CG: " << catGraph[v.cat1].size() << endl;

        //If we haven't visted either reachable cat and we have enough milk to visit it
        if (!count(V.begin(), V.end(), v.cat2) && v.dist < milk)
            currCat = v.cat2;
        else if (!count(V.begin(), V.end(), v.cat1) && v.dist < milk)
            currCat = v.cat1;
        else    //Get next to-do list item
            continue;
        // cout << "currCat: " << currCat << endl;

        //If we haven't visted the current cat
        if (!count(V.begin(), V.end(), currCat))
        {
            V.push_back(currCat);    //We visit this cat,
            milk -= v.dist+1;         //and expend the milk to get there.
            // cout << v;
            // cout << "Milk: " << milk << endl;
            for (auto i = catGraph[currCat].begin(); i != catGraph[currCat].end(); i++)   
            {   //add all connected cats to the to-do list.
                if ( ((*i).cat1 == currCat || (*i).cat2 == currCat) && v.dist < milk)
                    T.push(*i);
            }
        }
        if (V.size() == numCats || milk < 1)    //We've reached all the cats
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
        // cout << milkTotal << " " << numCats;
        catGraph.clear();
        for (int j = 0; j < numCats; j++)
        {
            vector<edge> cat;
            catGraph.push_back(cat);
        }
        // cout << "---------- " << catGraph.size() << "\n";
        int loop = (numCats*(numCats - 1)) / 2; //Used for cin loop
        // cout << "Loop: " << loop << endl;
        for (int j = 0; j < loop; j++)
        {
            int cat1, cat2, dist;
            edge temp;
            cin >> cat1 >> cat2 >> dist;
            temp.cat1 = cat1;
            temp.cat2 = cat2;
            temp.dist = dist;
            // cout << temp;
            catGraph[cat1].push_back(temp);
            // cout << "B ";
            catGraph[cat2].push_back(temp);
            // cout << "C" << endl;
            //cout << j << " ";

        }
        //cout << "----------\n";
        //compute cat traveral and output result
        vector<int> result = MST();
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