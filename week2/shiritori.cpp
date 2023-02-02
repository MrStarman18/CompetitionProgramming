//Week 2 Kattis problem "Shiritori"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char*argv[])
{
    int numWords;
    std::cin >> numWords;

    bool gameActive = true;
    int currentPlayer = 1;  //0 for P1, 1 for P2
    int currentTotal = 0;   //Track number of words in list, for convenience
    char currentLetter = '*';   //Letter being played on
    std::string currentWord;

   std::set<std::string> wordsList;
    for (int loop = 0; loop < numWords && gameActive; loop++)
    {
        currentPlayer = !currentPlayer;
        cin >> currentWord;
        if (currentWord[0] != currentLetter && currentLetter != '*')
        {
            gameActive = false;
            break;
        }
        if (wordsList.count(currentWord))   //if word is already in the list (was entered before)
        {
            gameActive = false;
            break;
        }
        wordsList.insert(currentWord);
        currentLetter = currentWord.back();
        ++currentTotal;
    }

    if (gameActive)
        cout << "Fair Game\n";
    else
        cout << "Player " << (currentPlayer + 1) << " lost\n";

}