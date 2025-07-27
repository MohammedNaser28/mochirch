#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

long long modpow(long long base, long long exp, long long modulus) {
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

long long modinverse(long long a, long long m) {
    return modpow(a, m - 2, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> segments(n);
    vector<vector<int>> start(m + 2), end(m + 2);
    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        segments[i] = {l, r, p, q};
        start[l].push_back(i);
        end[r + 1].push_back(i);
    }

    long long inv_1 = 1; // Tracks product of (1 - p_i/q_i) for active segments
    long long sum_p_inv = 0; // Tracks sum of (p_i/q_i) / (1 - p_i/q_i) for active segments
    long long res = 1;

    set<int> active;
    for (int x = 1; x <= m; ++x) {
        // Process segments ending at x-1 (i.e., starting end at x)
        for (int i : end[x]) {
            auto [l, r, p, q] = segments[i];
            long long prob = p * modinverse(q, MOD) % MOD;
            long long not_prob = (1 - prob + MOD) % MOD;
            long long term = modinverse(not_prob, MOD);
            inv_1 = inv_1 * term % MOD;
            sum_p_inv = (sum_p_inv - prob * modinverse(not_prob, MOD)) % MOD;
            if (sum_p_inv < 0) sum_p_inv += MOD;
            active.erase(i);
        }
        // Process segments starting at x
        for (int i : start[x]) {
            auto [l, r, p, q] = segments[i];
            long long prob = p * modinverse(q, MOD) % MOD;
            long long not_prob = (1 - prob + MOD) % MOD;
            inv_1 = inv_1 * not_prob % MOD;
            sum_p_inv = (sum_p_inv + prob * modinverse(not_prob, MOD)) % MOD;
            active.insert(i);
        }
        if (active.empty()) {
            res = 0;
            break;
        }
        long long current = sum_p_inv * inv_1 % MOD;
        res = res * current % MOD;
    }

    cout << res << '\n';
    return 0;
}