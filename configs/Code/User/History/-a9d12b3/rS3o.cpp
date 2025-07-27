// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 18:47:25
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

ll dfs(int l, int r, const vector<int>& p, const vector<int>& idx, vector<int>& depth) {
    if (l > r) return 0;
    int m = l;
    for (int i = l; i <= r; ++i)
        if (p[i] > p[m]) m = i;

    ll d = max(dfs(l, m - 1, p, idx, depth), dfs(m + 1, r, p, idx, depth)) + 1;
    depth[m] = d;
    return d;
}

void pewpew() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> depth(n);
    dfs(0, n - 1, p, {}, depth);

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    
}

signed main() {
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x --> 0) {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//