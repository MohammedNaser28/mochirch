// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

const vector<int> small_primes = {2, 3, 5, 7};

ll pewpew(ll n)
{
    if (n < 1)
        return 0;
    ll res = n;
    int sz = small_primes.size();
    for (int mask = 1; mask < (1 << sz); ++mask)
    {
        ll prod = 1;
        int bits = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (mask & (1 << i))
            {
                prod *= small_primes[i];
                ++bits;
            }
        }
        if (prod > n)
            continue;
        ll cnt = n / prod;
        if (bits % 2 == 1)
            res -= cnt;
        else
            res += cnt;
    }
    return res;
}

int main()
{
    mochi;
    int x_x = 1;
    cin >> x_x;
    while (x_x-- > 0)
    {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//