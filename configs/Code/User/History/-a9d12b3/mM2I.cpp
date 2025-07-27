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

int longestDecreasingSubseq(const vector<int>& a) {
    int n = a.size();
    int best = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (a[i] > a[j] && a[j] > a[k])
                    best = max(best, 3);
                else if (a[i] > a[j])
                    best = max(best, 2);
    return best;
}

void pewpew() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    ll total = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < min(n, l + 5); ++r) {
            vector<int> sub(p.begin() + l, p.begin() + r + 1);
            total += longestDecreasingSubseq(sub);
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