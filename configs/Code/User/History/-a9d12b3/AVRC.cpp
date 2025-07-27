#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mochi ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i =0; i<n; i++) cin >> p[i];

    // dp[r]: length of longest contiguous decreasing suffix ending at r
    vector<ll> dp(n);
    dp[0] = 1;
    ll total = dp[0]; // subarrays ending at 0: only 1

    for (int r = 1; r < n; ++r) {
        if (p[r-1] > p[r]) dp[r] = dp[r-1] + 1;
        else dp[r] = 1;
        // كل subarray من l..r تنتهي عند r وسلسلة أقصى LDS بها = dp[r]
        total += dp[r];
    }

    cout << total << "\n";
}

int main() {
    mochi;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
