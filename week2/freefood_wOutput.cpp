//Week 2 Kattis problem "Free Food"
#include <iostream>
using namespace std;

int findLargest(int* calendar, int calendarSize)   //use to find latest date
{      
    int largest = 0;
    for (int loop = 0; loop < (calendarSize); loop++)
    {
        if (calendar[loop] > largest)
            largest = calendar[loop];
    }
    return largest;
}

int main(int argc, char*argv[])
{
    int numOfEvents;
    std::cin >> numOfEvents;
    numOfEvents *= 2;
    int*calendar = new int[numOfEvents]{0};

    for (int loop = 0; loop < (numOfEvents); loop++)  //cin range of dates
     {   std::cin >> calendar[loop];
        cout << loop << " " << calendar[loop] << endl;
     }
cout << "A\n";
    int largest = findLargest(calendar, numOfEvents);
    int* foodDates = new int[largest + 1]{0}; //Default to no food available on any day

    for (int loop = 0; loop < (numOfEvents); loop+= 2)  //Iterate calendar 1 date range at a time
    {
        for (int small = calendar[loop], large = calendar[loop+1]; small <= large; small++) //Looks at the current date range
            if (foodDates[small] != 1)
                foodDates[small] = 1;       //Food is available on this day
    }
cout << "B\n";
    //Output
for (int loop = 0; loop < largest; loop++)
    cout << foodDates[loop] << " ";
cout << "foodDates final\n";
    int total = 0;
    for (int loop = 0; loop <= largest; loop++)
        if (foodDates[loop] != 0)
        {
            total += 1;
            cout << "loop: " << loop << " foodDates: " << foodDates[loop] << " total: " << total << endl;
        }   
    std::cout << total << endl;

    //Destruct
    delete[] calendar;
    delete[] foodDates;
    calendar = nullptr;
    foodDates = nullptr;
}