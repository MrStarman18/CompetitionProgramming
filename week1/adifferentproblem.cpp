//Week 1 Kattis problem "A Different Problem"
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
    int first, second;
    while (std::cin >> first >> second)
    {   
        std::cout << abs((first - second)) << std::endl;
    }
}