#include <bits/stdc++.h>
using namespace std;

const int MOD = 908244353;
const int MAXN = 1005;

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
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), p(m), q(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    // dp[i][j][cov] = number of ways to cover first i cells using j segments
    // where cov is the count of cells covered exactly once up to i
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(2, 0)));
    dp[0][0][0] = 1; // Base case

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int cov = 0; cov <= 1; cov++) {
                dp[i][j][cov] = 0;
                for (int k = 0; k < j; k++) {
                    if (l[k] <= i && i <= r[k]) {
                        long long prob = (long long)p[k] * modinverse(q[k], MOD) % MOD;
                        long long not_prob = (1 - prob + MOD) % MOD;
                        for (int prev_cov = 0; prev_cov <= 1; prev_cov++) {
                            long long ways = dp[i-1][k][prev_cov];
                            if (ways == 0) continue;
                            int new_cov = prev_cov;
                            if (prob > 0 && prev_cov == 0) new_cov = 1; // New coverage
                            dp[i][j][new_cov] = (dp[i][j][new_cov] + ways * prob) % MOD;
                        }
                    }
                }
            }
        }
    }

    long long y = dp[n][m][1]; // Probability of all cells covered exactly once
    if (y == 0) {
        cout << 0 << endl;
    } else {
        long long y_inv = modinverse(y, MOD);
        cout << y_inv << endl;
    }

    return 0;
}