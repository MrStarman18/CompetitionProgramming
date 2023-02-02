//Week 2 Problem "ASCII Addition"
#include <iostream>
#include <string>
using namespace std;

void makeNumber(string matrix, string * number)
{
    switch (matrix)
    {
        case one:
            *number += "1";
            break;
        case two:
            *number += "2";
            break;
        case three:
            *number += "3";
            break;
        case four:
            *number += "4";
            break;
        case five:
            *number += "5";
            break;
        case six:
            *number += "6";
            break;
        case seven:
            *number += "7";
            break;
        case eight:
            *number += "8";
            break;
        case nine:
            *number += "9";
            break;
    }


}
int main(int argc, char*argv[])
{
    //Concatenated versions of each number.
    string one = "....x....x....x....x....x....x....x";
    string two = "xxxxx....x....xxxxxxx....x....xxxxx";
    string three = "xxxxx....x....xxxxxx....x....xxxxxxx" ;
    string four = "x...xx...xx...xxxxxx....x....x....x";
    string five = "xxxxxx....x....xxxxx....x....xxxxxx" ;
    string six = "xxxxxx....x....xxxxxx...xx...xxxxxx";
    string seven = "xxxxx....x....x....x....x....x....x";
    string eight = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    string nine = "xxxxxx...xx...xxxxxx....x....xxxxxx";
    string zero = "xxxxxx...xx...xx...xx...xx...xxxxxxx";
    string plus = ".......x....x..xxxxx..x....x.......";
    std::string matrix1{""}, number1{""};
    std::string matrix2{""}, number2{""};
    
    //For digit in input (digit != plus?)
        cin >> matrix1;
        makeNumber(matrix1, number1);

    //Repeat for matrix2. So make into function?

    //Add together
    int output = stoi(number1) + stoi(number2);

    //Convert output to a string of matrices and print

}

//Within loop(?) concatenate strings by 7x5 matrix and check for numbers here.
//concatenate these to a separate string, which will then be converted to integers after math.
