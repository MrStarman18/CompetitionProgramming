//Week 12 Kattis problem Family DAG
#include <iostream>
#include <set>
using namespace std;

struct relation {
    string parent;
    string child;
};
relation relationships[100];
set<string> people;
int n = 0;

set<string> peopleTried;
string currPerson;
int currParadox;

void check(string person)
{
    peopleTried.insert(person);
    //cout << currPerson << " checking " << person << "\n";
    for (int i = 0; i < n; i++) //iterate relationships
    {
        //cout << relationships[i].child << " ";
        if (relationships[i].child == person)
            if (peopleTried.find(relationships[i].parent) == peopleTried.end()) //parent not in set
            {
                peopleTried.insert(relationships[i].parent);
                check(relationships[i].parent);
            }    
            else //parent is in set
            {
                if (relationships[i].parent == currPerson)
                    {currParadox = 2;}
                else if (currParadox < 2)
                    {currParadox = 1;}
            }   
    }
    //cout << endl;
}

int main()
{
    string x = "\0";
    while (cin >> x)
    {
        n = 0;
        people.clear();
        while (x != "done") //cin all relationships
        {
            relationships[n].parent = x;
            people.insert(relationships[n].parent);
            cin >> x >> relationships[n].child;
                            //cout << x << " " << relationships[n].child << endl;
            people.insert(relationships[n].child);
            n++;
            cin >> x;
                            //cout << x << " ";
        }

        for (auto i = people.begin(); i != people.end(); i++) //iterate all relationships
        {
            currParadox = 0;
            currPerson = *i;
            peopleTried.clear();
            check(*i);
            if (currParadox == 2)
                cout << currPerson << " paradox\n";
            else if (currParadox == 1)
                cout << currPerson << " hillbilly\n";
        }
        cout << endl; //<< "----------------\n";
    }
}