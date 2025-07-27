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

const ll MOD = 998244353;
ll add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }

ll modpow(ll base, ll exp, ll mod = MOD)
{
    ll res = 1;
    while (exp)
    {
        if (exp & 1)
            res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

ll modinv(ll x, ll mod = MOD) { return modpow(x, mod - 2, mod); }

vector<ll> fact, inv;
void precompute(int n)
{
    fact.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = modinv(fact[i]);
    }
}
ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return mul(fact[n], mul(inv[r], inv[n - r]));
}

void pewpew()
{
}

signed main()
{
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x-- > 0)
    {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//