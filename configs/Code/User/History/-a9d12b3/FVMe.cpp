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

ll build(int l, int r, const vector<int> &p, vector<int> &depth)
{
    if (l > r)
        return 0;

    int max_i = l;
    for (int i = l + 1; i <= r; ++i)
    {
        if (p[i] > p[max_i])
            max_i = i;
    }

    ll d = max(build(l, max_i - 1, p, depth), build(max_i + 1, r, p, depth)) + 1;
    depth[max_i] = d;
    return d;
}

void pewpew()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    vector<int> depth(n);
    build(0, n - 1, p, depth);

    ll total = 0;
    for (int i = 0; i < n; ++i)
    {
        total += depth[i] * 1LL * (i + 1) * (n - i);
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