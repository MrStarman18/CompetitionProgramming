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
    int n, s, m;
    cin >> n >> s >> m;
    cout << n << " " << s << " " << m << endl;
    int i = 0, j = 200;
    while (1)
    {
        //Forgive the syntax. Wanted some variety in test cases, w/o iterating the loop an odd # of times.
        cout << randomNumber(0, n) << " " << randomNumber(-i, n) << " ";
        i+=2; j--;   if (i >= n) break; if (j <= 0) j = 200;
        cout << randomNumber(i, n) << " " << randomNumber(j, n) << " ";
        i+=2; j--;   if (i >= n) break; if (j <= 0) j = 200;
        cout << randomNumber(-i, j) << " " << randomNumber(0, n) << " ";
        i+=2; j--;   if (i >= n) break; if (j <= 0) j = 200;
        cout << randomNumber(-200, i) << " " << randomNumber(-200, j) << " ";
        i+=2; j--;   if (i >= n) break; if (j <= 0) j = 200;

        //Stack Overflow jargon. Delays the program, but needed since randomNumber() is based on time.
        sleep_for(10ns);
        sleep_until(system_clock::now() + 100ns);
    }
}