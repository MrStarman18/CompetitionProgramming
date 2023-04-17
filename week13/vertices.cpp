//Week 12 Kattis problem Weak Vertices
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int matrix[20][20] {0};
    bool strong;
    while(cin >> n)
    {
        //make matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                {
                    cin >> matrix[j][i];
                }
        if (n == -1)
            exit(0);   
        
        for (int row = 0; row < n; row++)
        {
            strong = false;
            for (int col = 0; col < n; col++)
            {
                if(matrix[row][col] == 1)       //if a vertex
                    for (int i = 0; i < n; i++) //iterate that vertex's row
                    {
                        if (matrix[col][i] == 1)    //if vertex has a vertex
                            if(matrix[row][i] == 1)
                                strong = true;
                    }
            }
            if (strong == false)
                cout << row << " ";
        } 
        cout << endl;
    }
}