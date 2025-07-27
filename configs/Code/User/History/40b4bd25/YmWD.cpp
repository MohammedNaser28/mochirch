/*
    You are given an integer . Consider the binary representation of this
    number without leading zeroes. You can rotate the binary representation
    of this number by moving its bits to the left end, where the leftmost bit
    moves to the rightmost position.
    Your task is to find the maximum integer you can obtain after performing
    any number of rotations on the binary representation, without adding any
    leading zeroes.

    Input
        The first line contains the number of test cases t (1 <= t <= 1e5).
        Each test case contains one integer n (1 <= n <= 1e9).

    Output
        Output a single integer, the maximum integer you can obtain after
        performing any number of rotations
*/

// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

string get_binary(int n) {
    if (n == 0) {
        return "0";
    }
    string res;
    while (n > 0) {
        res += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void binary_to_decimal(const string& bin) {
    int result = 0;
    for (char c : bin) {
        result = result * 2 + (c - '0');
    }
    cout << result << '\n';
}
void pewpew() {
    int n;
    cin >> n;
    string bin = get_binary(n);
    int ones = __popcount(n);
    
}

signed main() {
    mochi;
    int x_x = 1;
    cin >> x_x;
    while (x_x --> 0) {
        pewpew();
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//