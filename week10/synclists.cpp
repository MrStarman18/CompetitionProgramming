//Week 10 Kattis problem Synchronizing Lists
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n = 69; //!= 0
    
    while (69)
    {
        set<int> setOne, setTwo;
        vector<int> vectOne, vectOneAsc;
        cin >> n;
        if (n == 0)
            break;
        int middleMan;
        for (int i = 0; i < n; ++i)
        {
            cin >> middleMan;
            setOne.insert(middleMan);  //ordered ascending
            vectOne.push_back(middleMan);   //in proper order
        }
        for (auto i = setOne.begin(); i != setOne.end(); ++i)
        {
            vectOneAsc.push_back(*i);   //ordered asc. AND accessible by index
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> middleMan;
            setTwo.insert(middleMan);   //ordered ascending
        }
        
        for (int i = 0; i < n; ++i) //iterate through vectOne
        {
            //cout << *(std::next(setOne.begin(), i)) << " " << *(std::next(setTwo.begin(), i))<< " " << vectOne[i] << " " << vectOneAsc[i] << endl;
            
            middleMan = vectOne[i];                                 //get value from listOne
            auto found = find(vectOneAsc.begin(), vectOneAsc.end(), middleMan);                    //find iterator to value in asc. listOne, setOne
            int index = found - vectOneAsc.begin();                     //compute the index of value in setOne
            cout << *(std::next(setTwo.begin(), index)) << endl;    //print the related value from setTwo
        }
        cout << "\n";
    }
}