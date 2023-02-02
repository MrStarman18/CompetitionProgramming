//Week 3 Problem Bit by Bit
#include <iostream>
#include <string>
using namespace std; 

char booland(char i, char j)    //Not stopping at first if statement (?). Even when trading  
                                //first statement for '0' or '1' it won't execute it. Why?
{
    if (i == '?' || j == '?')       //If either is '?', can't be determined
        return '?';   
    else if (i == '1' && j == '1')
        return '1';
    else
        return '0';
}
char boolor(char i, char j)
{
    if (i == '1' || j == '1')       //If either is true, OR is true
        return '1';
    else if (i == '?' || j == '?')  //If no 1 visible and one is '?'
        return '?';
    else                            //both 0
        return '0';
}

int main()  //Important to note: Bits indexed backwards
{
    int n{9}, currentIndex1, currentIndex2;
    std::string instruction;
    while (n != 0)
    {
        char bits[32]{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?'};
        cin >> n;
        if (n == 0) //signals end of input
            break;
        
        for (int testCase = 0; testCase < n; testCase++)
        {
            cin >> instruction;
            if (instruction == "SET")
            {
                cin >> currentIndex1;
                bits[31 - currentIndex1] = '1';
            }
            else if (instruction == "CLEAR")
            {
                cin >> currentIndex1;
                bits[31 - currentIndex1] = '0';
            }
            else if (instruction == "AND")
            {
                cin >> currentIndex1 >> currentIndex2;
                bits[31 - currentIndex1] = booland(bits[31-currentIndex1], bits[31-currentIndex2]);

            }
            else if (instruction == "OR")
            {
                cin >> currentIndex1 >> currentIndex2;
                bits[31 - currentIndex1] = boolor(bits[31-currentIndex1], bits[31-currentIndex2]);
            
            }
        }
        for(int loop = 0; loop < 32; loop++)
        {
            cout << bits[loop];
        }
        cout << endl;
    }
}