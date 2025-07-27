/*
    Wu-Tang is a highly skilled kung fu player capable of using his head, legs,
    or arms in combat. One day, he found himself trapped in a cave filled with
    monsters that he must defeat in a specific order. Each monster has a
    strength denoted as si, and Wu-Tang can choose to attack using one of
    three methods: head, legs, or arms, which inflict h, l and a damage,
    respectively.
    However, Wu-Tang must follow a strict rule: for each monster, he can
    choose only one method to attack, but he cannot use the same method
    consecutively for the next monster. This means if he defeats a monster
    using his head, the next monster cannot be attacked with his head again,
    but must be attacked with either his legs or arms.
    The objective is for Wu-Tang to defeat all the monsters in the minimum
    number of hits while adhering to this rule.

    Input
    The first line of the input contains four integers n, h, l, a
        — the number of monsters, the amount of damage for head, leg, arm, respectively.
    the second line of the input contains n integers
        — the strength for each monster.

    Output
    Output a single integer, the minimum number of operations to defeat all
    monsters.
*/
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
    ll n, h, l, a;
    cin >> n >> h >> l >> a;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    vector<ll> d = {h, l, a};

    // last: 0 = head, 1 = leg, 2 = arm, 3 = none
    const ll INF = LLONG_MAX/2 ;
    vector<vector<ll>> dp(n + 1, vector<ll>(4, INF));
    dp[0][3] = 0; // No attack used

    for (int i = 0; i < n; ++i)
    {
        for (int last = 0; last < 4; ++last)
        {
            if (dp[i][last] == INF)
                continue;
            for (int curr = 0; curr < 3; ++curr)
            {
                if (curr == last)
                    continue;
                ll hits = (s[i] + d[curr] - 1) / d[curr];
                dp[i + 1][curr] = min(dp[i + 1][curr], dp[i][last] + hits);
                // debug2(i, dp[i + 1][curr]);
            }
        }
    }

    ll result = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << result << '\n';
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