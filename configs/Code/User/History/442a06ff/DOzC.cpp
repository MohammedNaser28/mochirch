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

vector<int> tD = {
    11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

vector<ll> gNums;

void generate_good_numbers()
{
    set<ll> seen;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(1);
    seen.insert(1);

    while (!pq.empty())
    {
        ll curr = pq.top();
        pq.pop();
        if (curr >= 2)
            gNums.push_back(curr);
        for (int p : tD)
        {
            if (curr > 1e18 / p)
                continue; // avoid overflow
            ll nxt = curr * p;
            if (!seen.count(nxt))
            {
                seen.insert(nxt);
                pq.push(nxt);
            }
        }
    }
    sort(gNums.begin(), gNums.end());
}

void pewpew()
{
    ll l, r;
    cin >> l >> r;
    auto it1 = lower_bound(gNums.begin(), gNums.end(), l);
    auto it2 = upper_bound(gNums.begin(), gNums.end(), r);
    cout << it2 - it1 << '\n';
}

int main()
{
    mochi;
    generate_good_numbers();
    int x_x = 1;
    cin >> x_x;
    while (x_x-- > 0)
    {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//