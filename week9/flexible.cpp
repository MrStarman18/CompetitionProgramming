//Week 9 Kattis problem Flexible Spaces
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> partitions;
set<int> spacesMade;

int main()
{
    int width, partCount, input;
    cin >> width >> partCount;
    partitions.push_back(0);    //left wall

    for (int i = 0; i < partCount; i++) //input partitions. partition[0] == 0
    {   
        cin >> input;
        partitions.push_back(input);
    }
    partitions.push_back(width);    //right wall

    int currentWidth;   //value was long and used it a lot
    for (int left = 0; left < partitions.size(); left++) //iterate left partitions
    {
        for (int right = left; right < partitions.size(); right++) //iterate all partitions to the right of j partition
        {
            currentWidth = partitions[right] - partitions[left];
            if (spacesMade.find(currentWidth) == spacesMade.end() && currentWidth != 0)  //if made width not already counted..
            {
                spacesMade.insert(currentWidth);                    //add this width to set
            }
        }
    }

    //print all spaces made (sorts into increasing order)
    for (set<int>::iterator i = spacesMade.begin(); i != spacesMade.end(); i++) 
    {
        cout << *i << " ";
    }
 

}
