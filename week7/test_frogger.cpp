#include <iostream>
using namespace std;

int main()
{
    cout << 100 << " " << 0 << " " << 0 << endl;
    for (int i = 50; i > 1; i--)
        cout << i << " ";
    cout << 0 << " ";
    for (int i = -1; i >= -50; i--)
        cout << i << " ";
    cout << endl;
}