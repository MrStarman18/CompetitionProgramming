#include <iostream>

int main()
{ 
    int n, array[4];
    std::cin >> n;
    for (int i= 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
    int s[4]; int dp[4]; int k;
    s[0]=array[0];
    dp[0]=s[0];
 k = 2;
 for(int i = 1; i < n; i ++)
 {
    s[i] = s[i-1] + k*array[i];
    dp[i] = dp[i-1] + s[i];
    k = k * 2;
 }
 std::cout << dp[n-1] << std::endl;

}