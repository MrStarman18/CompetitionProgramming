//Week 14 Kattis problem Block Crusher
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct xy   //used to store coordinates
{   
    int x;
    int y;
    int value;
};
int h = -1, w = -1; //height and width of block
string block[20];   //holds each line of the block
xy fracture[20];    //holds the path through the block (final answer)
int shortest = 999;

void shortestPath(int startX, int startY)
{
    vector<xy> V;             //Visited tiles
    int d[20][60] {999999};     //distance array
    d[startX][startY] = 0;
    int currDist = 0;

    priority_queue<xy> t;  //contains values at points traversed
    t.push({startX, startY, (int)block[startX][startY]});
    xy tile = {-1, -1, -1};

    int localDist = 0;      //Local variables for comparison to global bests
    xy localFracture[20];

    int x = startX, y = startY; 
    while (!count(V.begin(), V.end(), tile)) //while v is not in V
    {
        tile = t.top();
        t.pop();
        if (!count(V.begin(), V.end(), tile))
        {
            V.push_back(tile);
            y++;
            for (int i = -1; i <= 1; i++)
            {
                if (currDist < d[x+i][y])
                {
                    d[x+i][y] = currDist + (int)block[x+i][y];
                    localFracture[y] = tile;
                }
                if((i > -1 && tile.x != 0) || (i < 1 && tile.x != w))
                t.push({tile.x+i, y, (int)block[tile.x+i][y]});  //push the coords and values of the three subsequent tiles
            }
        }

    }
    if (currDist < shortest)
    {
        shortest = currDist;
        for (int i = 0; i < 20; i++)
            fracture[i] = localFracture[i];
    }
   /*
    Let D be an array/map with initial values of (infinity)
    D[v] = 0
    Let T be a priority queue               //T = "to-do"
    T.push(v)                               //priority queue needs to be used "backwards" to return smallest cost first
    while some v is not in V do
        v = T.pop()
        if v is not in V then
            V.add(v)
            for all edges leaving v to w do
                
                if d = D[w]
                    D[w] = d
                T.push(v-w edge cost)
    */

}

int main()
{
    while(69)
    {
        cin >> h >> w;
        if (h == 0)
            break;
        string line = "";   
        //store each line, for cout at end of test case
        for (int i = 0; i < h; i++) 
        {
            block[i] = "";      //clear array
            cin >> line;
            block[i] = line;    //reset array  
        }
        for (int i = 0; i < w; i++) //Check paths starting from each number in the first row
        {
            shortestPath(i, 0);
        }
        for (int i = 0; i < h; i++) //Add fracture to block and cout answer
        {
            int x = fracture[i].x;
            block[i].replace(x, 1, " ");  
            cout << block[i] << endl;
        }
        cout << endl;
    }
}