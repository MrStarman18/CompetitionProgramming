//Week 4 Kattis problem What does the fox say?
#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main()
{
    int n;
    std::cin >> n;
    string recording, sound; 
    set <string> noises;
    std::string currNoise;
    for (int i = 0; i < n; i++)
    {
        getline(cin, recording, '\n');  //ERROR: Not moving on after this, reading this string again in second getline()
        stringstream recordStream(recording);
        int c = 0;
        while (1)   //add animal noises to set
        {
            currNoise = "";
            cin.ignore(100, ' '); 
            cin.ignore(100, ' ');
            getline(cin, currNoise, '\n');
            //cout << currNoise << endl << endl;
            if (currNoise.find("the fox say?") != string::npos)
                break;
            if (c > 0)     //Attempting to resolve error where the whole recording would be read twice.
            {
                noises.insert(currNoise);
                cout << currNoise << endl;
            }   
            c++;
        }

        //Compare recording to noises set and output result
        while (recordStream >> sound)  //Read individual sound strings from recording stringstream 
        {
            cout << "sound: " << sound << "count: " << noises.count(sound) << endl;
            if (noises.count(sound) != true)
                cout << sound;
        }

        for (int i = 0; recordStream >> sound; i++)
        {
            
        }
        cout << endl;
    }
}