#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

ll add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }

ll modpow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp) {
        if (exp & 1)
            res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

ll modinv(ll x, ll mod = MOD) { return modpow(x, mod - 2, mod); }

vector<ll> fact, inv;
void precompute(int n) {
    fact.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = modinv(fact[i]);
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return mul(fact[n], mul(inv[r], inv[n - r]));
}

void solve() {
    int t;
    cin >> t;
    vector<pair<int, int>> queries(t);
    int maxN = 0;

    for (int i = 0; i < t; ++i) {
        cin >> queries[i].first >> queries[i].second;
        maxN = max(maxN, max(queries[i].first, queries[i].second));
    }

    precompute(maxN);

    for (auto &[n, x] : queries) {
        if (n > x)
            cout << 0 << '\n';
        else
            cout << nCr(x, n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
//-------------------------------------Ende-----------------------------------------//