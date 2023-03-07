#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //cin game info
    int numSpaces, start, magic, temp, total = 0;
    cin >> numSpaces >> start >> magic;
    vector <int> board;
    vector <int> visited;
    board.push_back(0);
    for (int i = 0; i < numSpaces; i++)
    {
        cin >> temp;
        board.push_back(temp);
    }

    int frog = start;   //1 <= Start <= numSpaces

    while (1)
    {
        //if visited contains location, break for inf. loop
        if (find(visited.begin(), visited.end(), frog) != visited.end()) 
        {
            cout << "cycle\n";
            break;
        }   
        else                //read in location, add to visited
        {                  
            visited.push_back(frog);
        } 

        //if at goal location
        if (board[frog] == magic) 
        {
            cout << "magic\n";
            break;
        }
        //else plan to move
        total++;
        if (frog + board[frog] < 1)
        {
            cout << "left\n";
            break;
        }    
        else if (frog + board[frog] > numSpaces)
        {
            cout << "right\n";
            break;
        }
        else                    //location is valid. move
            frog += board[frog];     
    }
    cout << total << endl;
}