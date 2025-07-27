// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 18:47:25
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

void pewpew() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> dp(n, 1);
    ll total = 0;

    // Process in reverse to make sure all subsequences are decreasing
    for (int i = n - 2; i >= 0; --i) {
        if (p[i] > p[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }

    // Use a stack to simulate all subarrays and calculate LDS
    for (int l = 0; l < n; ++l) {
        int maxLDS = 1;
        for (int r = l; r < n; ++r) {
            if (r > l && p[r] < p[r - 1]) {
                ++maxLDS;
            } else if (r > l) {
                maxLDS = 1;
            }
            total += maxLDS;
        }
    }

    cout << total << '\n';
}
signed main()
{
    mochi;
    int x_x = 1;
    cin >> x_x;
    while (x_x-- > 0)
    {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//