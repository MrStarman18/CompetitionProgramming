#include <iostream>
using namespace std;

int main()
{
    long N, K, i{1};
    cin >> N;
    while(cin >> N && cin >> K)
    {
        cout << "Case #" << i << ": ";
        if((K+1) % (1<<N) == 0)
        {
            cout << "ON";
        }
        else
        {
            cout << "OFF";
        }
        cout << endl;
        i++;
    }
}