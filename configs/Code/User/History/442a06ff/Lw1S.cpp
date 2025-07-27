// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

vector<int> tD = {
    11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};

vector<ll> gNums;

void dfs(int idx, ll curr) {
    if (curr > 1e18) return;
    if (idx == tD.size()) {
        if (curr >= 2) gNums.push_back(curr);
        return;
    }
    ll val = 1;
    while (curr * val <= 1e18) {
        dfs(idx + 1, curr * val);
        val *= tD[idx];
    }
}

void precompute_good_numbers() {
    dfs(0, 1);
    sort(gNums.begin(), gNums.end());
    gNums.erase(unique(gNums.begin(), gNums.end()), gNums.end());
}

ll count_good_in_range(ll l, ll r) {
    // lower_bound
    // upper_bound
    auto it1 = lower_bound(gNums.begin(), gNums.end(), l);
    auto it2 = upper_bound(gNums.begin(), gNums.end(), r);
    return it2 - it1;
}

void pewpew() {
    ll l, r;
    cin >> l >> r;
    cout << count_good_in_range(l, r) << '\n';
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