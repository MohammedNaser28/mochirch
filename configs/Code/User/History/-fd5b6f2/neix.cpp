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

const int MOD = 998244353;

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

struct Segment
{
    int l, r;
    int prob, one_minus_prob;
};

void pewpew()
{
    int n, m;
    cin >> n >> m;

    vector<Segment> seg(n);
    vector<vector<int>> covers(m + 2);

    for (int i = 0; i < n; ++i)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int inv_q = modinv(q);
        int prob = mul(p, inv_q);
        int one_minus = sub(1, prob);
        seg[i] = {l, r, prob, one_minus};
        for (int j = l; j <= r; ++j)
            covers[j].push_back(i);
    }

    ll ans = 1;
    for (int i = 1; i <= m; ++i)
    {
        const auto &ids = covers[i];
        int sz = ids.size();

        if (sz == 0)
        {
            ans = 0;
            break;
        }

        vector<ll> pref(sz + 1, 1), suff(sz + 2, 1);
        for (int j = 0; j < sz; ++j)
            pref[j + 1] = mul(pref[j], seg[ids[j]].one_minus_prob);
        for (int j = sz - 1; j >= 0; --j)
            suff[j + 1] = mul(suff[j + 2], seg[ids[j]].one_minus_prob);

        ll prob_i = 0;
        for (int j = 0; j < sz; ++j)
        {
            ll here = seg[ids[j]].prob;
            here = mul(here, pref[j]);
            here = mul(here, suff[j + 2]);
            prob_i = add(prob_i, here);
        }

        ans = mul(ans, prob_i);
    }

    cout << ans << '\n';
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
