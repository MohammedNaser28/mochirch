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
    int prob;         // p_i * q^-1 % MOD
    int neg_prob;     // (q - p) * q^-1 % MOD
};

void pewpew() {
    int n, m;
    cin >> n >> m;

    if (n > 20) {
        cout << "Too big for brute force!\n";
        return;
    }

    vector<Segment> seg(n);
    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int inv_q = modinv(q);
        int prob = 1LL * p * inv_q % MOD;
        int neg_prob = (1 - prob + MOD) % MOD;
        seg[i] = {l, r, prob, neg_prob};
    }

    int ans = 0;
    int total_masks = 1 << n;

    for (int mask = 0; mask < total_masks; ++mask) {
        vector<int> cover(m + 1, 0);
        int prob = 1;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                // segment i is active
                prob = 1LL * prob * seg[i].prob % MOD;
                for (int j = seg[i].l; j <= seg[i].r; ++j)
                    cover[j]++;
            } else {
                prob = 1LL * prob * seg[i].neg_prob % MOD;
            }
        }

        bool valid = true;
        for (int i = 1; i <= m; ++i) {
            if (cover[i] != 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ans = (ans + prob) % MOD;
        }
    }

    cout << ans << '\n';
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