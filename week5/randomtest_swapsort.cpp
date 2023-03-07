//Default functionality, but 1-indexed rather than 0-indexed.
#include <iostream>
#include <chrono>
#include <thread>
//#include <cstdlib>  //rand()
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int randomNumber(int low, int high)
{
    if (low > high) //logic requires a positive number. abs() may work too
    {
        int mid = low;
        low = high;
        high = mid;
    }

    srand(time(NULL));
    int range = (high - low) + 1;
    return low + (rand() % range);
}

int main(int argc, char* argv[])
{
    int n, k;
    cin >> n >> k;
    cout << n << " " << k << endl;
    int i = 1, j = n;
    while (1)
    {
        //Forgive the syntax. Wanted some variety in test cases, w/o iterating the loop an odd # of times.
        cout << randomNumber(1, n) << " " << randomNumber(i, n) << endl;
        i++; j--;   if (i > k) break; if (j <= 1) j = n;
        cout << randomNumber(i, n) << " " << randomNumber(j, n) << endl;
        i++; j--;   if (i > k) break; if (j <= 1) j = n;
        cout << randomNumber(i, j) << " " << randomNumber(1, n) << endl;
        i++; j--;   if (i > k) break; if (j <= 1) j = n;
        cout << randomNumber(1, i) << " " << randomNumber(1, j) << endl;
        i++; j--;   if (i > k) break; if (j <= 1) j = n;

        //Stack Overflow jargon. Delays the program, but needed since randomNumber() is based on time.
        sleep_for(10ns);
        sleep_until(system_clock::now() + 100ns);
    }
}