// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 18:08:09
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

bool bad(const vector<ll> &dep)
{
    int n = dep.size();
    if (n < 5)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i + 4 < n; ++i)
        {
            if (dep[i] < dep[i + 1] && dep[i + 1] < dep[i + 2] && dep[i + 2] < dep[i + 3] && dep[i + 3] < dep[i + 4])
                return 1;
            if (dep[i] > dep[i + 1] && dep[i + 1] > dep[i + 2] && dep[i + 2] > dep[i + 3] && dep[i + 3] > dep[i + 4])
                return 1;
        }
    }
    return 0;
}
void pewpew()
{
    int n;
    cin >> n;
    vector<ll> deq(n);
    for
}

signed main()
{
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x-- > 0)
    {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//