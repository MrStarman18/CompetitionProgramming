//Week 9 Kattis problem Peg Solitaire
#include <iostream>
using namespace std;
string board[5];
int pegsleft = 9;

void checkboard () {
    int pegs = 0;
        for (int i = 0; i < 5; i++) {
            for ( int j = 0; j < 9; j++) {
                if(board[i][j] == 'o') {
                    if(i > 1 && board[i-1][j] == 'o' && board[i-2][j] == '.') { // up
                        board[i][j] = '.';
                        board[i-1][j] = '.';
                        board[i-2][j] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i-1][j] = 'o';
                        board[i-2][j] = '.';
                    }
                    if(i < 3 && board[i+1][j] == 'o' && board[i+2][j] == '.') { // down
                        board[i][j] = '.';
                        board[i+1][j] = '.';
                        board[i+2][j] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i+1][j] = 'o';
                        board[i+2][j] = '.';
                    }
                    if(j > 1 && board[i][j-1] == 'o' && board[i][j-2] == '.') { // left
                        board[i][j] = '.';
                        board[i][j-1] = '.';
                        board[i][j-2] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i][j-1] = 'o';
                        board[i][j-2] = '.';
                    }
                    if(j < 7 && board[i][j+1] == 'o' && board[i][j+2] == '.') { // right
                        board[i][j] = '.';
                        board[i][j+1] = '.';
                        board[i][j+2] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i][j+1] = 'o';
                        board[i][j+2] = '.';
                    }
                    pegs++;
                }

            }
        }
    if(pegsleft > pegs)
        pegsleft = pegs;
}

int main() {
    string input;
    int t;
    cin >> t;
    for(int l = 0; l < t; l++) {
        pegsleft = 9;
        int starting_pegs = 0; 
        for (int i = 0; i < 5; i++) {
            cin >> input;
            for ( int j = 0; j < 9; j++)
                starting_pegs += int(input[j] == 'o');
            board[i] = input;
        }
        checkboard();
        cout << pegsleft << " " << starting_pegs - pegsleft << endl;
    }
}
#include <iostream>
using namespace std;
string board[5];
int pegsleft = 9;

void checkboard () {
    int pegs = 0;
        for (int i = 0; i < 5; i++) {
            for ( int j = 0; j < 9; j++) {
                if(board[i][j] == 'o') {
                    if(i > 1 && board[i-1][j] == 'o' && board[i-2][j] == '.') { // up
                        board[i][j] = '.';
                        board[i-1][j] = '.';
                        board[i-2][j] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i-1][j] = 'o';
                        board[i-2][j] = '.';
                    }
                    if(i < 3 && board[i+1][j] == 'o' && board[i+2][j] == '.') { // down
                        board[i][j] = '.';
                        board[i+1][j] = '.';
                        board[i+2][j] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i+1][j] = 'o';
                        board[i+2][j] = '.';
                    }
                    if(j > 1 && board[i][j-1] == 'o' && board[i][j-2] == '.') { // left
                        board[i][j] = '.';
                        board[i][j-1] = '.';
                        board[i][j-2] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i][j-1] = 'o';
                        board[i][j-2] = '.';
                    }
                    if(j < 7 && board[i][j+1] == 'o' && board[i][j+2] == '.') { // right
                        board[i][j] = '.';
                        board[i][j+1] = '.';
                        board[i][j+2] = 'o';
                        checkboard();
                        board[i][j] = 'o';
                        board[i][j+1] = 'o';
                        board[i][j+2] = '.';
                    }
                    pegs++;
                }

            }
        }
    if(pegsleft > pegs)
        pegsleft = pegs;
}

int main() {
    string input;
    int t;
    cin >> t;
    for(int l = 0; l < t; l++) {
        pegsleft = 9;
        int starting_pegs = 0; 
        for (int i = 0; i < 5; i++) {
            cin >> input;
            for ( int j = 0; j < 9; j++)
                starting_pegs += int(input[j] == 'o');
            board[i] = input;
        }
        checkboard();
        cout << pegsleft << " " << starting_pegs - pegsleft << endl;
    }
}
