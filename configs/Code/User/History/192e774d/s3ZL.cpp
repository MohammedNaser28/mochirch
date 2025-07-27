// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 17:44:06
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

const int MAXN = 30;
const int MAXMASK = (1 << MAXN);

ll dp[MAXMASK];
int n;
ll c;
vector<ll> a;

ll solve(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];

    int cnt = __builtin_popcount(mask);
    ll res = 1e18;

    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            // Number of doublings = cnt - 1 (bags left before this step)
            ll weight = a[i] << (cnt - 1);
            ll cost = (weight > c ? 1 : 0);
            res = min(res, cost + solve(mask ^ (1 << i)));
        }
    }
    return dp[mask] = res;
}

void pewpew() {
    cin >> n >> c;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int full_mask = (1 << n) - 1;
        fill(dp, dp + (1 << n), -1);

        cout << solve(full_mask) << '\n';

}

signed main() {
    mochi;
    int x_x = 1;
    cin >> x_x;
    while (x_x --> 0) {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//