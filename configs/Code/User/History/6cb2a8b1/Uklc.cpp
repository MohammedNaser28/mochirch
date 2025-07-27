// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
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

void pewpew()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<int> max_step(n);
    max_step[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        max_step[i] = max(max_step[i - 1], a[i]);
    }

    for (int i = 0; i < q; ++i)
    {
        int k;
        cin >> k;
        int idx = upper_bound(max_step.begin(), max_step.end(), k) - max_step.begin();
        cout << prefix[idx] << " ";
    }
    cout << "\n";
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