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
    for (int& x : p) cin >> x;

    ll total = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && p[j] > p[j + 1]) j++;
        int len = j - i + 1;
        total += 1LL * len * (len + 1) / 2;
        i = j + 1;
    }

    cout << total << "\n";
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