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

bool is_bad(vector<int> &last)
{
    if (last.size() < 5)
        return false;
    bool inc = true, dec = true;
    for (int i = 0; i < 4; ++i)
    {
        if (last[i] >= last[i + 1])
            inc = false;
        if (last[i] <= last[i + 1])
            dec = false;
    }
    return inc || dec;
}

bool bad(vector<int> &last)
{
    if (last.size() < 5)
        return false;
    bool inc = true, dec = true;
    for (int i = 0; i < last.size(); ++i)
    {
        if (last[i] >= last[i + 1])
            inc = false;
        if (last[i] <= last[i + 1])
            dec = false;
    }
    return inc || dec;
}

bool dfs(deque<int> &dq, vector<int> &result, string &path, vector<int> last4)
{
    if (dq.empty())
        return true;

    int left = dq.front();
    dq.pop_front();
    vector<int> l4 = last4;
    l4.push_back(left);
    if (l4.size() > 5)
        l4.erase(l4.begin());
    if (!is_bad(l4))
    {
        path.push_back('L');
        result.push_back(left);
        if (dfs(dq, result, path, l4))
            return true;
        result.pop_back();
        path.pop_back();
    }
    dq.push_front(left); 

    int right = dq.back();
    dq.pop_back();
    vector<int> r4 = last4;
    r4.push_back(right);
    if (r4.size() > 5)
        r4.erase(r4.begin());
    if (!is_bad(r4))
    {
        path.push_back('R');
        result.push_back(right);
        if (dfs(dq, result, path, r4))
            return true;
        result.pop_back();
        path.pop_back();
    }
    dq.push_back(right); 

    return false;
}

void pewpew()
{
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; ++i)
        cin >> dq[i];

    vector<int> result;
    string path;
    vector<int> last4;

    dfs(dq, result, path, last4);

    cout << path << "\n";
}

int main()
{
    mochi;
    int t;
    cin >> t;
    while (t--)
        pewpew();
    return 0;
}
//-------------------------------------Ende-----------------------------------------//