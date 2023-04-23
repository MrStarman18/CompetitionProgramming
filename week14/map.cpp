//Week 14 Kattis problem Lost Map
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{    //describes the distance between 2 cats
    int vil1;
    int vil2;
    int dist;
    friend bool operator< (edge const& lhs, edge const& rhs) {
        return lhs.dist > rhs.dist;
    }
    friend void operator <<(ostream &oss, edge const& e) {
        oss << e.vil1 << " " << e.vil2 << " " << e.dist << '\n';
    }
};
int mapGraph[2500][2500];  //Store distance between all villages
int numVils; //Store number of villages
vector<string> result;  //The answer

void MST()
{
    vector<int> V;
    priority_queue<edge> T;
    T.push({1, 1, 0});
    int currVil;
    edge v;
    while(!T.empty())
    {
        // cout << "A\n";
        v = T.top();
        T.pop();
        currVil = v.vil2;
        if (V.size() == numVils)    //We've reached all the villages
            break;

        if (!count(V.begin(), V.end(), currVil))    //If village not stored already
        {
            V.push_back(currVil);                   
            if (v.vil1 != v.vil2)
                result.push_back(to_string(v.vil1+1) + " " + to_string(v.vil2+1) );
            //add all connected villages to the to-do list.  
            for (int i = 0; i < numVils; i++)
            {                    
                T.push({currVil, i, mapGraph[currVil][i]});
            }
        }
        else
            continue;
            
    }
}

int main()
{
        cin >> numVils;
        for (int j = 0; j < numVils; j++)
        {
            for (int i = 0; i < numVils; i++)
                scanf("%i", &mapGraph[j][i]);
        }
        
        //compute map traveral and output result
        MST();
        for (auto i = result.begin(); i != result.end(); i++)
        {
            cout << (*i) << endl;
        }
}
