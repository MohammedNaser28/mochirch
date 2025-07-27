/*
The elections for the new mayor of Ducks City are approaching, and Amin,
the current mayor, will do anything to keep his position. As the mayor,
Amin has access to lots of information about Ducks City and he has
decided to use it to his advantage.
Amin knows that for each poster he puts on a lighting pole, he gets one
vote guaranteed. Ducks City has n poles.
The cost of putting one poster on a pole equals hi + x * k.
    hi is the height of the pole and is the number of posters already on the pole.
    k is the number of posters already on the pole

Amin knows that he needs m votes to win the elections.

Although Amin became filthy rich from being the mayor, he still wants to
save money. He has decided to ask for your help. Help him by calculating
the minimum cost that will make him win the elections.

Input
    The first line of each test has one integer t (to 1e5) The number of test cases.
        The first line of each testcase has three integers n, m and x
            The number of poles in Ducks City (to 1e5)
            Ther equired number of votes (to 1e5)
            The integer x (to 1e9).
        The second line of each testcase has n integers (hi) (to 1e9)
            The height of the light poles.
    The summation of n and m over all testcases doesn't exceed 1e5.

Output
    A single integer the minimum cost that guarantees that Amin wins the
    elections.
*/

// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-24 15:06:50
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
    int n, m;
    ll x;
    cin >> n >> m >> x;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

    for (int i = 0; i < n; ++i)
    {
        pq.emplace(h[i], i, 1);
    }

    ll total_cost = 0;
    while (m--)
    {
        auto [cost, idx, k] = pq.top();
        pq.pop();
        total_cost += cost;

        ll next_cost = h[idx] + x * k;
        pq.emplace(next_cost, idx, k + 1);
    }

    cout << total_cost << '\n';
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