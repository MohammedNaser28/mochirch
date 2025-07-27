// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 17:44:06
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
#define setbit(x, i) (x |= (1LL << i))
#define clearbit(x, i) (x &= ~(1LL << i))
#define togglebit(x, i) (x ^= (1LL << i))
#define checkbit(x, i) ((x & (1LL << i)) != 0)
#define lsb(x) (x & (-x))
#define msb(x) (63 - __builtin_clzll(x))
#define popcount(x) __builtin_popcountll(x)


ll solve(int mask, vector<ll> &dp, int n, ll c, const vector<ll> &a)
{
    if (mask == 0)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int cnt = popcount(mask);
    ll res = 1e18;

    for (int i = 0; i < n; ++i)
    {
        if (mask & (1 << i))
        {
            ll weight = a[i] << (cnt - 1); 
            ll cost = (weight > c ? 1 : 0);
            res = min(res, cost + solve(mask ^ (1 << i), dp, n, c, a));
        }
    }
    return dp[mask] = res;
}

void pewpew()
{
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int mask = (1 << n) - 1;
    vector<ll> dp(1 << n, -1);

    cout << solve(mask, dp, n, c, a) << '\n';
}

int main()
{
    mochi;
    int t;
    cin >> t;
    while (t--)
    {
        pewpew();
    }
    return 0;
}

//-------------------------------------Ende-----------------------------------------//