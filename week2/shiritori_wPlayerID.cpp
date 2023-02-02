//Week 2 Kattis problem "Free Food"
#include <iostream>
#include <string>
using namespace std;
//This version of the program includes prompts for which player should be inputting.

int main(int argc, char*argv[])
{
    int numWords;
    std::cin >> numWords;

    bool gameActive = true;
    int currentPlayer = 1;  //0 for P1, 1 for P2
    int currentTotal = 0;   //Track number of words in list, for convenience
    char currentLetter = '*';   //Letter being played on
    std::string currentWord;

    std::string * wordsList = new string[numWords];
    for (int loop = 0; loop < numWords && gameActive; loop++)
    {
        currentPlayer = !currentPlayer;
        cout << (currentPlayer + 1) << ": ";
        cin >> currentWord;
        if (currentWord[0] != currentLetter && currentLetter != '*')
        {
            cout << "CurrentLetter: " << currentLetter << endl;
            cout << "currentWord[0]: " << currentWord[0] << endl;
            gameActive = false;
            break;
        }
        for (int search = 0; search <= currentTotal; search++)
            if (wordsList[search] == currentWord)
            {
                gameActive = false;
                break;
            }
        wordsList[loop] = currentWord;
        currentLetter = currentWord.back();
        ++currentTotal;
    }

    if (gameActive)
        cout << "Fair Game\n";
    else
        cout << "Player " << (currentPlayer + 1) << " lost\n";

    //Destruct
    delete[] wordsList;
    wordsList = nullptr;
}