#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int instruments[1000][1001];
int song[1001];
int cache[1005][1005];

bool contains(int note, int instrumentIndex) {
    return instruments[instrumentIndex][note];
}

int f(int instrumentIndex, int noteIndex) {
    int mins = 999999; 
    int fboy;
    int switched = 0;
    if (noteIndex == m) {
        // cout << "hello!";
        return 0;
    }
    if(contains(song[noteIndex], instrumentIndex)) {
        if (cache[instrumentIndex][noteIndex+1] == 999999 ) {
            // cout << "getting f of " << instrumentIndex << " " << noteIndex+1 << endl;
            mins = f(instrumentIndex, noteIndex+1);
        }
        else {
            // cout << "getting cache of " << instrumentIndex << " " << noteIndex+1 << endl;
            mins = cache[instrumentIndex][noteIndex+1];
        }
    }
    else {
        switched = 1;
        for(int i = 0; i < n; i++){
            if(contains(song[noteIndex],i)) {
                if (cache[i][noteIndex] == 999999 ) {
                    fboy = f(i, noteIndex);
                    // cout << "Getting f of " << i << " " << noteIndex << endl;
                }
                else {
                    // cout << "Getting cache of " << i << " " << noteIndex << endl;
                    fboy = cache[i][noteIndex];
                }
                mins = min(fboy,mins);
            }
        }
    }
    cache[instrumentIndex][noteIndex] = mins+switched;
    return mins+switched;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++){
            cache[i][j] = 999999;
        }
    }
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            instruments[i][j] = 0;
        }
    }
    for(int i = 0; i < n; ++i) { //take in instruments
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            int y;
            cin >> y;
            instruments[i][y] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> song[i];
    }
    int mins = 99999;
    for(int i = 0; i < n; i ++) {
        if(contains(song[0],i))
            mins = min(mins, f(i,0));
    }
    cout << mins;
}