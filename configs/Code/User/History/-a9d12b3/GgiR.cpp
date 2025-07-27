#include <bits/stdc++.h>
using namespace std;

#define mochi ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int MAX = 5e5 + 5;

struct BIT {
    vector<int> tree;
    BIT(int n) : tree(n + 2, 0) {}

    void update(int i, int val) {
        while (i < tree.size()) {
            tree[i] = max(tree[i], val);
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, tree[i]);
            i -= i & -i;
        }
        return res;
    }
};

int compressed[MAX];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    vector<int> sorted;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted.push_back(a[i]);
    }

    // Coordinate compression
    sort(sorted.begin(), sorted.end(), greater<int>());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    auto get_idx = [&](int x) {
        return lower_bound(sorted.begin(), sorted.end(), x, greater<int>()) - sorted.begin() + 1;
    };

    BIT bit(n + 5);
    int total = 0;

    for (int i = 0; i < n; ++i) {
        int idx = get_idx(a[i]);
        dp[i] = bit.query(idx - 1) + 1;
        bit.update(idx, dp[i]);
        total += dp[i];
    }

    cout << total << '\n';
}

int32_t main() {
    mochi;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
