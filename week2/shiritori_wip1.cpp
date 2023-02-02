//Week 2 Kattis problem "Free Food"
#include <iostream>
#include <string>
using namespace std;
//The counting words and player tracking works, but doesn't check word endings/beginnings

int main(int argc, char*argv[])
{
    int numWords;
    std::cin >> numWords;

    bool gameActive = true;
    int currentPlayer = 0;  //0 for P1, 1 for P2
    int currentTotal = 0;
    std::string currentWord;

    std::string * wordsList = new string[numWords];
    for (int loop = 0; loop < numWords && gameActive; loop++)
    {
        cin >> currentWord;
        for (int search = 0; search <= currentTotal; search++)
            if (wordsList[search] == currentWord)
            {
                gameActive = false;
                break;
            }
        wordsList[loop] = currentWord;
        ++currentTotal;
        currentPlayer = !currentPlayer;
    }

    if (gameActive)
        cout << "Fair Game\n";
    else
        cout << "Player " << currentPlayer << " lost\n";

    //Destruct
    delete[] wordsList;
    wordsList = nullptr;
}