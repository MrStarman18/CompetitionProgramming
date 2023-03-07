#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct ware { //this is for the sorting. Not important to the map
    int count;
    string name;
};

int main() 
{
    string inputS, inputI;
    cin >> inputI;
    int t = stoi(inputI);
    for(int k = 0; k < t; k++)
    {
        map<string, int> wares; //Heres the map
        cin >> inputI;
        int n = stoi(inputI);
        for (int i = 0; i < n; i++)
        {
            cin >> inputS >> inputI;
            if(wares.find(inputS) == wares.end()) //Checks if the key isn't already in the map. find() returns a iterator to the end if it isn't.
                wares[inputS] = stoi(inputI); //If isn't, add it.
            else
                wares[inputS] += stoi(inputI); //Otherwise jjust add the amount of the item.
        }
        ware sortedWares[100];
        int j = 0;
        for (map<string, int>::iterator i = wares.begin(); i != wares.end(); ++i) //This just goes through the map
        {
            sortedWares[j].name = i -> first; // first is the key, which in this is the ware name
            sortedWares[j].count = i -> second; // second is the value, which in this is the ware count
            j++;
        }

        stable_sort(sortedWares, sortedWares+j, [](const ware &a,const ware &b){
            if(a.count != b.count) return a.count > b.count;
            if(a.name != b.name) return a.name < b.name;
            else return false;
        });
        cout << j << endl;
        for(int i = 0; i < j; i++)
        {
            cout << sortedWares[i].name << " " << sortedWares[i].count << endl;
        }
    }
}