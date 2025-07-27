/*
One day, Sherlock and Watson were sitting next to the fire and talking.
Sherlock was telling Waston how much he likes palindromes and that he
wants everything in this world to be a palindrome.

A palindrome is a string that reads the same way backward as forward; for
example, strings 1, 111 and 101 are palindromes, but strings 110 and 10
are not.

Watson asked Sherlock if he could form a palindrome from some zeros
and ones. Sherlock solved this problem in no time. He asked Watson if he
could tell him the second lexicographically smallest palindrome that can
be formed.

A string a is lexicographically smaller than a string b if, in the first position
where a and b differ, the string a has a letter that appears earlier in the
alphabet than the corresponding letter in b.

Input
    The first line contains a single integer — the number of test cases t (1 ≤ t ≤ 1e3)
        The first and only line of each test case contains two integers
        a and b (0 ≤ a, b ≤ 1e5) — the number of zeros and ones respectively.
    It's guaranteed that for each test case a + b ≥ 1.
    It's guaranteed that the sum of a + b over all test cases doesn't exceed 4e5.

Output
    For each test case, print second lexicographically smallest palindrome
    that can be formed or -1 if there is no such palindrome.
*/

// g++ -o c c.cpp && ./c
// Created by HP on 2025-07-24 14:13:13
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void pewpew() {
    int a, b;
    cin >> a >> b;
    int n = a + b;

    int odd = (a % 2) + (b % 2);
    if ((n % 2 == 0 && odd != 0) || (n % 2 == 1 && odd != 1)) {
        cout << -1 << endl;
        return;
    }

    int zeros = a / 2, ones = b / 2;
    string left;
    left += string(zeros, '0');
    left += string(ones, '1');
    sort(all(left));
    string mid = "";
    if (a % 2) mid = "0";
    else if (b % 2) mid = "1";

    string right = left;
    reverse(all(right));

    string pal = left + mid + right;
    debug(pal);
    string ans = pal;
    int len = pal.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (ans[i] != ans[j]) {
                swap(ans[i], ans[j]);
                string rev = ans;
                reverse(all(rev));
                debug(rev);
                if (ans == rev && ans > pal) {
                    cout << ans << endl;
                    return;
                }
                swap(ans[i], ans[j]); 
            }
        }
    }

    cout << -1 << endl;
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