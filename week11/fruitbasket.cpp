#include <iostream>
using namespace std;
typedef long long ll; 
ll n;
ll w[42];
ll cache[42][40001];

ll weightCheck(ll index, ll total);
ll cacher(ll index, ll total) {
    if(cache[index][total] == -1)
        return cache[index][total] = weightCheck(index, total);
        return cache[index][total];
}
ll weightCheck(ll index, ll total)
{
    if (index == n) {
        if (total >= 200)
            return total;
        return 0;
    }

    ll on  = cacher(index+1, total);
    ll off = cacher(index+1, total+w[index]);
    return on + off;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < 41; ++i)
        for (ll j = 0; j < 40001; ++j)
            cache[i][j] = -1;
    for (ll i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    cout << weightCheck(0, 0) << '\n';
}