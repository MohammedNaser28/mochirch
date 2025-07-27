// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-27 18:08:09
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

bool bad(const vector<ll>& dp) {
    int n = dp.size(); 
    if (n < 5) {
        return 0;
    }
    else {
        if (dp[i] < dp[i+1] && dp[i+1] < dp[i+2] && dp[i+2] < dp[i+3] && dp[i+3] < dp[i+4])
            return true;
        if (dp[i] > dp[i+1] && dp[i+1] > dp[i+2] && dp[i+2] > dp[i+3] && dp[i+3] > dp[i+4])
            return true;
    }
}
void pewpew() {
    
}

signed main() {
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x --> 0) {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//