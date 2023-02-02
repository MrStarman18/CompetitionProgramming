//Week 1 Kattis problem "ACM Contest Scoring"
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
    int timeSubmitted{0};
    char problemLetter;
    std::string isAccepted;

    char problemAttempts[101]{'*'};
    int totalSolved{0}, totalTime{0};
    cin >> timeSubmitted;
    for (int loop{0}; timeSubmitted != -1; loop++)
    {
        //putting second cin here and omitting clause from line 13 gave right execution flow but output totalTime as 543.
        if (isAccepted == "right")
        {
            //Tally total wrongs for this problem
            int problemWrongs{0};
            for (int loop2{0}; problemAttempts[loop2] != '*'; loop2++)
            {
                if (problemAttempts[loop2] == problemLetter)
                    ++problemWrongs;
            }
            //Update totals
            ++totalSolved;
            totalTime += ( timeSubmitted + (20 * problemWrongs) );
            cout << "totalSolved: " << totalSolved << " " << "totalTime: " << totalTime << endl;
        }

        //Store attempts on each problem. Only needed for computation on right answers.
        problemAttempts[loop] = problemLetter; 

        cin >> timeSubmitted;
        cin >> problemLetter >> isAccepted;
    }
    cout << totalSolved << " " << totalTime << endl;
}