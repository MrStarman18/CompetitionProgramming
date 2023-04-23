#include <utility>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int h, w;
string line;
struct xy {
    int x;
    int y;
};

struct tile {
    int x;
    int y;
    int dist = 999999;
    int value = 0;
    int from;
    friend bool operator< (tile const& lhs, tile const& rhs) {
        return lhs.dist > rhs.dist;
    }
};

tile block[60][20];
vector<xy> bestPath;
int bestDist = 999999;
priority_queue<tile> t;
tile v;

void push(int x, int y, int dist, int from) {
    tile pushing = block[x][y]; //not sure this is important anymore, but was there so that the orginal tile is unchanged.
    if(pushing.dist < dist + pushing.value) //don't push if it is a worse dist
        return;
    pushing.dist = dist + pushing.value;
    block[x][y].dist = dist + pushing.value; //this is important for the above if statement
    pushing.from = from; //values can be 1 (from right), 0 (from above), -1 (from left)
    t.push(pushing);
}

void SSSP() {
    t = priority_queue<tile>();
    for(int i = 0; i < w; i++)
        push(i,0,0,0); //push all starting tiles
    while(!t.empty()) {
        v = t.top();
        t.pop();
        block[v.x][v.y] = v;
        if(v.y == h-1) { //at bottom of block. aka found shortest path
            bestDist = v.dist;
            break;
        }
        push(v.x, v.y+1, v.dist, 0); // push down
        if(v.x > 0){ //push left
            push(v.x-1, v.y+1, v.dist, -1);
        }
        if(v.x < w-1) { //push right
            push(v.x+1, v.y+1, v.dist, 1);
        }
    }
}

int main() {
    while (true)
    {
        cin >> h >> w;
        if(h == 0)
            break;
        for(int i = 0; i < h; i++) {
            cin >> line;
            for(int j = 0; j < w; j++) {
                block[j][i].value = line[j]-48; //Justin, you were right.
                block[j][i].x = j;
                block[j][i].y = i;
            }
        }
    SSSP(); //Doesn't need to be a function, but is fine.
    while(v.y >= 1) {
        block[v.x][v.y].value = -1; //-1 means it is part of the fracture
        v = block[v.x-v.from][v.y-1];
    }
    block[v.x][v.y].value = -1; //for the last part of fracture
    for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(block[j][i].value == -1) //fracture
                    cout << " ";
                else
                    cout << block[j][i].value;
            }
        cout << endl;
    }
    cout << endl;
    }
    
}