#include <bits/stdc++.h>
using namespace std;

const int MOD = 908244353;
const int MAXN = 1005;

// Modular exponentiation
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

// Modular multiplicative inverse
long long modinverse(long long a, long long m) {
    return modpow(a, m - 2, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), p(m), q(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    // DP[i][j] = probability that first i cells are covered with exactly one segment
    // using first j segments
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1; // Base case: no cells, no segments used

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < j; k++) {
                if (l[k] <= i && i <= r[k]) {
                    // Probability of using segment k
                    long long prob_num = p[k];
                    long long prob_den = q[k];
                    long long not_prob_num = (q[k] - p[k] + MOD) % MOD;
                    long long not_prob_den = q[k];

                    // Combine with previous state
                    long long prev = dp[i-1][k];
                    if (prev == 0) continue;

                    // Update dp considering exactly one coverage
                    dp[i][j] = (dp[i][j] + prev * prob_num % MOD * modinverse(prob_den, MOD) % MOD) % MOD;
                }
            }
        }
    }

    // Find the total probability
    long long y = dp[n][m];
    if (y == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long y_inv = modinverse(y, MOD);
    long long x = y_inv;
    cout << x << endl;

    return 0;
}