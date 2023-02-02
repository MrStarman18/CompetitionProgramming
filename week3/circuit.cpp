#include <iostream>
#include <stack>
#include <string>

int main() {
    //1
    int n;
    std::cin >> n;
    bool truthTable[26] {false};

    //2
    for(int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        if(c == 'T')
            truthTable[i] = true;
        else 
            truthTable[i] = false;
    }
    (void)truthTable;

    std::stack<bool> boolStack;

    std::string operations;

    std::getline(std::cin, operations);
    std::getline(std::cin, operations);


    for(int i = 0; i < (int)operations.length(); i+=2) {
        if((int)operations[i] > 64 && (int)operations[i] < 91) {
            boolStack.push(truthTable[(int)operations[i]-65]);
        }else {
            if(operations[i] == '*') {
                bool r1 = boolStack.top();
                boolStack.pop();
                bool r2 = boolStack.top();
                boolStack.pop();
                bool result = r1 && r2;
                boolStack.push(result);
            }
            else if(operations[i] == '+') {
                bool r1 = boolStack.top();
                boolStack.pop();
                bool r2 = boolStack.top();
                boolStack.pop();
                bool result = r1 || r2;
                boolStack.push(result);
            }
            else {
                bool r1 = boolStack.top();
                boolStack.pop();
                boolStack.push(!r1);

            }

        }
    }
    if(boolStack.top())
        std::cout << 'T';
    else 
        std::cout << 'F';


}