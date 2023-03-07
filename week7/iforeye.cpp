#include <iostream>
#include <string>
#include <map>
using namespace std;

void makeDict(map &map)
{
    map['@'] = "at";
    map['&'] = "and";
    map['1'] = "one", "won";
    map['2'] = "to", "too", "two";
    map['4'] = "for", "four";
    map['b'] = "bea", "be", "bee";
    map['c'] = "sea", "see";
    map['i'] = "eye";
    map['o'] = "oh", "owe";
    map['r'] = "are";
    map['u'] = "you";
    map['y'] = "why";
}

int main()
{
    std::map<char, string> dict;
    makeDict(dict);
    int n; string tweet;
    cin >> n;
    /*iterate each given Tweet*/
    for (int i = 0; i < n; i++)
    {
        getline(cin, tweet);
        //iterate all elements of map
        for (auto it = dict.cbegin(); it != dict.cend(); it++)
            while (tweet.find(it->second) != string::npos) //tweet contains current string (right) element of dict
            {   
                //replace with matching char (left) element of dict 
                tweet.replace(tweet.find(it->second), it->second.length(), it->first);
            }

        //How to check for uppercase?

        cout << tweet << endl;
    }

}