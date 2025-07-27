#include <bits/stdc++.h>
using namespace std;

const int MOD = 908244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), p(m), q(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    // Probability of each cell being covered by a segment
    vector<double> prob(n + 1, 0.0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= l[j] && i <= r[j]) {
                prob[i] += (double)(p[j]) / q[j];
            }
        }
    }

    // Calculate the probability that each cell is covered exactly once
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        if (prob[i] == 1.0) {
            result = (result * 1) % MOD;
        } else {
            result = 0;
            break;
        }
    }

    cout << result << endl;
    return 0;
}