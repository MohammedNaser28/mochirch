// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

const int MOD = 998244353;

int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

int modinv(int x) {
    return modpow(x, MOD - 2);
}

struct Segment {
    int l, r;
    int p, q;
    int prob, inv_q, one_minus_prob;
};

void pewpew() {
    int n, m;
    cin >> n >> m;

    vector<Segment> seg(n);
    vector<vector<int>> covers(m + 2);  // cells covered by which segments (1-based index)

    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int prob = 1LL * p * modinv(q) % MOD;
        int one_minus_prob = (1 - prob + MOD) % MOD;
        seg[i] = {l, r, p, q, prob, modinv(q), one_minus_prob};

        for (int j = l; j <= r; ++j)
            covers[j].push_back(i);  // segment i covers cell j
    }

    int result = 1;
    for (int cell = 1; cell <= m; ++cell) {
        const auto& ids = covers[cell];
        int sz = ids.size();

        if (sz == 0) {
            result = 0;
            break;
        }

        int total = 0;
        for (int i = 0; i < sz; ++i) {
            int prod = seg[ids[i]].prob;
            for (int j = 0; j < sz; ++j) {
                if (i == j) continue;
                prod = 1LL * prod * seg[ids[j]].one_minus_prob % MOD;
            }
            total = (total + prod) % MOD;
        }
        result = 1LL * result * total % MOD;
    }

    cout << result << '\n';
}


signed main() {
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x --> 0) {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//