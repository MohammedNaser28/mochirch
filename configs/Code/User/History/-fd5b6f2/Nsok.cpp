#include <bits/stdc++.h>
using namespace std;

const int MOD = 908244353;

// Power function for modular exponentiation
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

// Modular multiplicative inverse using Fermat's little theorem
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

    // For each cell, calculate the probability it is covered
    vector<long long> cover_prob(n + 1, 0); // Numerator of probability
    vector<long long> denom = {1}; // Denominator (initialize with 1)

    for (int i = 1; i <= n; i++) {
        long long num = 0, den = 1;
        for (int j = 0; j < m; j++) {
            if (i >= l[j] && i <= r[j]) {
                // Combine probabilities: P + (1-P)*Q
                long long new_num = (p[j] * den % MOD + q[j] * (1LL * den - num) % MOD) % MOD;
                long long new_den = (q[j] * den) % MOD;
                num = new_num;
                den = new_den;
            }
        }
        cover_prob[i] = num;
        if (denom.size() <= i) denom.push_back(den);
        else denom[i] = den;
    }

    // Check if each cell is covered exactly once
    long long y = 1;
    for (int i = 1; i <= n; i++) {
        if (cover_prob[i] * modinverse(denom[i], MOD) % MOD != 1) {
            y = 0;
            break;
        }
    }

    long long y_inv = modinverse(y, MOD);
    long long x = y_inv;
    cout << x << endl;

    return 0;
}