//Week 14 Kattis problem Block Crusher
//This program contains the team's first attempt to solve.
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
    vector<xy> path;
    int x;
    int y;
    int dist = 0;
    int value = 0;
    friend bool operator< (tile const& lhs, tile const& rhs) {
        return lhs.dist < rhs.dist;
    }
};

tile block[60][20];
vector<xy> bestPath;
int bestDist = 999999;

void SSSP(tile start) {
    priority_queue<tile, vector<tile>, greater<int> > t;
    t.push(start);
    while(!t.empty()) {
        tile v;
        v = t.top();
        xy coord;
        coord.x = v.x;
        coord.y = v.y;
        v.path.push_back(coord);
        t.pop();
        if(v.y == h-1) {
            if(bestDist > v.dist) {
                bestPath = v.path;
                bestDist = v.dist;
            }
            break;
        }
        block[v.x][v.y+1].dist += block[v.x][v.y+1].value + v.dist;
        block[v.x][v.y+1].path = v.path;
        t.push(block[v.x][v.y+1]);
        if(v.x > 0){
            block[v.x-1][v.y+1].dist += block[v.x-1][v.y+1].value + v.dist;
            block[v.x-1][v.y+1].path = v.path;
            t.push(block[v.x-1][v.y+1]);
        }
        if(v.x < w-1) {
            block[v.x+1][v.y+1].dist += block[v.x+1][v.y+1].value + v.dist;
            block[v.x+1][v.y+1].path = v.path;
            t.push(block[v.x+1][v.y+1]);
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
                block[j][i].value = line[j];
                block[j][i].dist = line[j];
                block[j][i].x = j;
                block[j][i].y = i;
            }
        }
    for(int i = 0; i < w; i++) {
        SSSP(block[i][0]);
    }
    for(auto i = bestPath.begin(); i != bestPath.end(); i++) {
        cout << (*i).x << " " << (*i).y << endl;
    }
    cout << bestDist << endl;
    // procedure SSSP(v) is
    // let D be an array/map with initial values of ∞
    // D[v] ← 0
    // let T be a priority queue
    // T.push(v,0)
    // while not empty(T) do
    //     v = T.pop()
    //     for all edges leaving v to w do   
    //         d ← D[v] + v-w edge cost
    //         if d < D[w] 
    //             D[w] ← d
    //             T.push(w,d)
    // D[] contains length of shortest path
    }
    
}