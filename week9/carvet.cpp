//Week 9 Kattis problem Flexible Spaces
#include <iostream>
#include <vector>
using namespace std;

int moveCount = 1000000;
int m, n, emptyX, emptyY, targetX, targetY;
vector<int> best, current;
vector<vector<int>> lot(250);


void lotCheck(int lastCar)
{
    //cout << lastCar << " ";
    if (emptyX+1 == targetX && emptyY+1 == targetY)
    {
        if (current.size() > best.size())
            best = current;
        //else if (current.size() == best.size())
            //Set to "lexicographically first"
    }

    //check left
    if (emptyX > 1 && lot[emptyX-1][emptyY] == lot[emptyX-2][emptyY] && lot[emptyX-2][emptyY] != lastCar)
    {
        int lastLastCar = lastCar;
        lastCar = lot[emptyX-2][emptyY];
        lot[emptyX][emptyY] = lot[emptyX-2][emptyY];
        lot[emptyX-2][emptyY] = -1;
        emptyX -=2;
        current.push_back(lastCar);
        lotCheck(lastCar);
        current.pop_back();
        lot[emptyX][emptyY] = lot[emptyX+2][emptyY];    //undo recursion
        lot[emptyX+2][emptyY] = -1;
        emptyX +=2;
        lastCar = lastLastCar;  
    }

    //check right
    //width && continuous car && not lastCar
    if (emptyX < m-2 && lot[emptyX+1][emptyY] == lot[emptyX+2][emptyY] && lot[emptyX+2][emptyY] != lastCar)
    {
        int lastLastCar = lastCar; 
        lastCar = lot[emptyX+2][emptyY];
        lot[emptyX][emptyY] = lot[emptyX+2][emptyY];
        lot[emptyX+2][emptyY] = -1;
        emptyX +=2;

        current.push_back(lastCar);
        lotCheck(lastCar);
        current.pop_back();

        lot[emptyX][emptyY] = lot[emptyX-2][emptyY];    //undo recursion
        lot[emptyX-2][emptyY] = -1;
        emptyX -=2;
        lastCar = lastLastCar;   
    }

    //move up
    if (emptyY > 1 && lot[emptyX][emptyY-1] == lot[emptyX][emptyY-2] && lot[emptyX][emptyY-2] != lastCar)
    {
        int lastLastCar = lastCar; 
        lastCar = lot[emptyX][emptyY-2];
        lot[emptyX][emptyY] = lot[emptyX][emptyY-2];
        lot[emptyX][emptyY-2] = -1;
        emptyY -=2;

        current.push_back(lastCar);
        lotCheck(lastCar);
        current.pop_back();
        
        lot[emptyX][emptyY] = lot[emptyX][emptyY+2];    //undo recursion
        lot[emptyX][emptyY+2] = -1;
        emptyY +=2;
        lastCar = lastLastCar;   
    }

    //move down
    if (emptyY < n-2 && lot[emptyX][emptyY+1] == lot[emptyX][emptyY+2] && lot[emptyX][emptyY+2] != lastCar)
    {
        int lastLastCar = lastCar; 
        lastCar = lot[emptyX][emptyY+2];
        lot[emptyX][emptyY] = lot[emptyX][emptyY+2];
        lot[emptyX][emptyY+2] = -1;
        emptyY +=2;

        current.push_back(lastCar);
        lotCheck(lastCar);
        current.pop_back();
        
        lot[emptyX][emptyY] = lot[emptyX][emptyY-2];    //undo recursion
        lot[emptyX][emptyY-2] = -1;
        emptyY -=2;
        lastCar = lastLastCar;   
    }
    //make move
        //call again based on new space
        //undo move
}

int main()
{
    cin >> m >> n;
    int middleMan;

    for (int i = 0; i < m; i++) //input the lot
    {
        for (int j = 0; j < n; j++)
        {
            cin >> middleMan;
            lot[i].push_back(middleMan);
            if (middleMan == -1)
            {
                emptyX = i;
                emptyY = j;
            }
        }
    }
    cin >> targetX >> targetY;

    lotCheck(-3);

    if (best.empty())
        cout << "impossible";
    else   
        for (auto i = best.begin(); i != best.end(); i++)
        {
            cout << *i << " ";
        }
}