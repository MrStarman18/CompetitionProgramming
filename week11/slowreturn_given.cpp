//Week 11 Athene problem Slowest Return
//"Partial solution, but it is really slow"
#include <iostream>
using namespace std;

// slowest ending at N
int _slowest(int height[], int n)
{
    if (n == 0)
        return 0;
 
    int max = 1;
    for (int i=0; i<n; i++)
        if (height[i] > height[n]) {
            int s = _slowest(height,i) + 1;
            if (s > max)
                max = s;
        }

    return max;
}

int slowest(int height[], int n)
{
    int max = 0;
    for (int i=0; i<n; i++) {
        int s = _slowest(height,i);
        if (s > max) 
            max = s;
    }
    return max;
}

int main()
{
    int h[1000];
    int n = 0;
    int x;
    while (cin >> x)
        h[n++] = x;
    cout << slowest(h, n) << endl;
}
