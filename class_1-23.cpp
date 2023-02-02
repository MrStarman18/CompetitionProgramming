#include <iostream>
using namespace std;

struct X
{
    int x;
    string y;
    char z;
};

//Sorting algorithm example for 
int main()
{
    X array[] = {
        {3, "abc", 'x'},
        {5, "abc", 'z'},
        {3, "def", 'z'},
        {3, "abc", 'x'},
        {5, "bbb", 'y'},
        {5, "def", 'y'},
    };
 
    sort(array, array + 6, [](X, &a, X &b))
    {
        if (a.n != b.n) return 
        if (a.s != b.s) return
        return a.c < b.c;
    }
}

//Infix notation: a + b     (a+b)*c
//Postfix notation: a b + c *
//In postfix notation, a and b are added to a stack, then both read from it when the + is called. This value is readded to stack.
//Numbers are added to the stack; operators are done on them.
/* Postfix 2 3 + 4 *
    ->
    -> 2
    -> 2 3
    -> 5
    -> 5 4
    -> 20
*/
//Infix: 3-2 = 1 // Postfix: 3 2 -
//Infix: -(7+3) 
/* Postfix: 7 3 + ~
    ->
    -> 7
    -> 7 3
    -> 10
    -> -10

    */
