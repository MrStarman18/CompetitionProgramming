//Week 4 Kattis Problem Dice Game
#include <iostream>
#include <string>
using namespace std;
/*Mathematically, this program works. I've confirmed the output values for the
three given test cases and confirmed it's all right. However, the Kattis problem expects a tie
for test 2, in which the totals are 4.5 and 4.92857. Storing totals as ints yields wrong answer
on the 4th test case.*/

int main()
{   //Declarations
    float gunnarTotal{0}, emmaTotal{0};
    float die1Low, die1High, die2Low, die2High;
  
    //Compute Gunnar's total
    std::cin >> die1Low >> die1High >> die2Low >>die2High;
    gunnarTotal = (die1Low + die1High)/2 + (die2Low + die2High)/2;
 
    //Compute Emma's total
    std::cin >> die1Low >> die1High >> die2Low >>die2High;
    emmaTotal = (die1Low + die1High)/2 + (die2Low + die2High)/2;

    //Cout the winner  
    if (gunnarTotal > emmaTotal)
        cout << "Gunnar\n";
    else if (gunnarTotal < emmaTotal)
        cout << "Emma\n";
    else 
        cout << "Tie\n";
}