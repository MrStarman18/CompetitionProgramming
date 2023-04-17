//Code to solve question 6 on Week 9's Quiz
#include <iostream>
using namespace std;
int main()
{
bool sol = false; int x, y, z;
int A = 1500, B = 1000, C = 10000;
for (x = -22; (x <= 22) && !sol; ++x) if (x*x <= C)
for (y = -100; (y <= 100) && !sol; ++y) if ((y != x) && (x*x + y*y <= C))
for (z = -100; (z <= 100) && !sol; ++z)
if ((z != x) && (z != y) &&
(x+y+z == A) && (x*y*z == B) && (x*x + y*y + z*z == C)) {
printf("%d %d %d\n", x, y, z);
sol = true;
}
}
