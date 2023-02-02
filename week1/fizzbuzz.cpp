//Week 1 Kattis problem "Fizzbuzz"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char*argv[])
{
    std::string output = "";
    int x, y, n;
    std::cin >> x >> y >> n;
    for (int loop{1}; loop <= n; loop++)
    {
        if (loop %  x == 0 && loop % y == 0)
            output += "FizzBuzz\n";
        else if (loop %  x == 0)
            output += "Fizz\n";
        else if (loop %  y == 0)
            output += "Buzz\n";
        else
            output += (std::to_string(loop) + '\n');
    }
    std::cout << output;

}