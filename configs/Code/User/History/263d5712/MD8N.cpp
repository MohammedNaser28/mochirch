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

bool bad(const vector<ll> &deq)
{
    int n = deq.size();
    if (n < 5)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i + 4 < n; ++i)
        {
            if (deq[i] < deq[i + 1] && deq[i + 1] < deq[i + 2] && deq[i + 2] < deq[i + 3] && deq[i + 3] < deq[i + 4])
                return 1;
            if (deq[i] > deq[i + 1] && deq[i + 1] > deq[i + 2] && deq[i + 2] > deq[i + 3] && deq[i + 3] > deq[i + 4])
                return 1;
        }
    }
    return 0;
}

bool is_good(const vector<ll> &q)
{
    int n = q.size();
    if (n < 5)
        return true;

    for (int i = 0; i + 4 < n; ++i)
    {
        if (q[i] < q[i + 1] && q[i + 1] < q[i + 2] && q[i + 2] < q[i + 3] && q[i + 3] < q[i + 4])
            return false;
        if (q[i] > q[i + 1] && q[i + 1] > q[i + 2] && q[i + 2] > q[i + 3] && q[i + 3] > q[i + 4])
            return false;
    }
    return true;
}

void pewpew()
{
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int l = 0, r = n - 1;
    vector<ll> q;
    string res = "";

    while (l <= r)
    {
        if (q.size() < 4)
        {
            if (p[l] < p[r])
            {
                q.push_back(p[l++]);
                res += 'L';
            }
            else
            {
                q.push_back(p[r--]);
                res += 'R';
            }
        }
        else
        {
            bool safeL = true, safeR = true;
            q.push_back(p[l]);
            if (bad(q))
                safeL = false;
            q.pop_back();

            q.push_back(p[r]);
            if (bad(q))
                safeR = false;
            q.pop_back();

            if (safeL)
            {
                q.push_back(p[l++]);
                res += 'L';
            }
            else if (safeR)
            {
                q.push_back(p[r--]);
                res += 'R';
            }
            else
            {
                q.push_back(p[l++]);
                res += 'L';
            }
        }
    }

    vector<ll> q;
    int l = 0, r = p.size() - 1;
    for (char c : s)
    {
        if (c == 'L')
            q.push_back(p[l++]);
        else
            q.push_back(p[r--]);
    }-
    if (is_good(q))
        cout << res << '\n';
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