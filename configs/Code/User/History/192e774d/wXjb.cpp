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

ll solve(int num, vector<ll> &dp, int n, ll c, const vector<ll> &a)
{
    if (num == 0)
        return 0;

    auto &root = dp[num];
    if (~root)
        return root;

    int cnt = popcount(num);
    ll res = 1e18;

    for (int i = 0; i < n; ++i)
    {
        if (num & (1 << i))
        {
            ll weight = a[i] << (cnt - 1);
            ll cost = (weight > c ? 1 : 0);
            res = min(res, cost + solve(num ^ (1 << i), dp, n, c, a));
        }
    }
    return root = res;
}

void pewpew()
{
    int n; ll c;
        cin >> n >> c;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;

        vector<int> deadline(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] > c) {
                deadline[i] = -1;                
            } else {
                ll rat = c / a[i];            
                int d = msb(rat);
                deadline[i] = d;
            }
        }

        // نرتبها تصاعديًا
        sort(deadline.begin(), deadline.end());

        int free_cnt = 0;       
        for (int d : deadline) {
            if (free_cnt <= d) 
                ++free_cnt;
        }
        cout << (n - free_cnt) << '\n'; 
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