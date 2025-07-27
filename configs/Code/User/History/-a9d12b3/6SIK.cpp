#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve_one(const vector<int> &p) {
    int n = p.size();
    ll res = 0;
    vector<int> v;

    for (int l = 0; l < n; ++l) {
        v.clear();
        for (int r = l; r < min(n, l + 5); ++r) {
            v.push_back(p[r]);
            // نحسب أطول LDS في v
            vector<int> dp;
            for (int x : v) {
                auto it = upper_bound(dp.begin(), dp.end(), x, greater<int>());
                if (it == dp.end())
                    dp.push_back(x);
                else
                    *it = x;
            }
            res += dp.size();
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        cout << solve_one(p) << '\n';
    }
}
