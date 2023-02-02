//Week 4 Kattis Problem Dice Game
#include <iostream>
#include <string>
using namespace std;
/*Mathematically, this program works. I've confirmed the output values for the
three given test cases and confirmed it's all right. However, the Kattis problem expects a tie
for test 2, in which the totals are 4.5 and 4.92857. Storing totals as ints yields the wrong answer.*/

int tally(int low, int high)    //Tally the total for one die
{
    int total = 0;
    for (int i = low; i <= high; i++)
        total += i;
    cout << total << " ";
    return total;
}

int main()
{   //Declarations
    std::string gunnar{""}, emma{""};
    float gunnarTotal{0}, emmaTotal{0};
    int numSides = 0;
    int die1Low, die1High, die2Low, die2High;

    //Compute Gunnar's total
    std::cin >> die1Low >> die1High >> die2Low >>die2High;
    numSides = (die1High - die1Low + 1) + (die2High - die2Low + 1);
    gunnarTotal = tally(die1Low, die1High) + tally(die2Low, die2High);
    gunnarTotal /=numSides;
    cout << "\nGunnar's numSides: " << numSides << endl;
    
    //Compute Emma's total
    std::cin >> die1Low >> die1High >> die2Low >>die2High;
    numSides = (die1High - die1Low + 1) + (die2High - die2Low + 1);
    emmaTotal = tally(die1Low, die1High) + tally(die2Low, die2High);
    emmaTotal /= numSides;
    cout << "\nEmma's numSides: " << numSides << endl;

    //Cout the winner
    cout << gunnarTotal << endl << emmaTotal << endl << endl;
    if (gunnarTotal > emmaTotal)
        cout << "Gunnar\n";
    else if (gunnarTotal < emmaTotal)
        cout << "Emma\n";
    else 
        cout << "Tie\n";
}