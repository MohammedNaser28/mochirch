#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mochi ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &x : b) cin >> x;

    if (b[0] != 1) {
        cout << "NO\n";
        return;
    }

    int sum = b[0];
    for (int i = 1; i < n; ++i) {
        if (b[i] > sum + 1) {
            cout << "NO\n";
            return;
        }
        sum += b[i];
    }

    cout << "YES\n";
}

int32_t main() {
    mochi;
    int t;
    cin >> t;
    while (t--) solve();
}
