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

bool isValidPalindrome(int a, int b) {
    int odd = 0;
    if (a % 2) odd++;
    if (b % 2) odd++;
    return odd <= 1;
}

string buildPalindrome(int a, int b) {
    int n = a + b;
    string s(n, '?');
    int l = 0, r = n - 1;

    // نحاول نضع أقل القيم الممكنة
    while (l < r) {
        if (a >= 2) {
            s[l] = s[r] = '0';
            a -= 2;
        } else if (b >= 2) {
            s[l] = s[r] = '1';
            b -= 2;
        } else {
            return ""; // مش ممكن تكوين Palindrome
        }
        l++, r--;
    }

    if (l == r) {
        if (a) s[l] = '0', a--;
        else if (b) s[l] = '1', b--;
        else return "";
    }

    if (a == 0 && b == 0) return s;
    return "";
}

string secondLexSmallest(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (s[i] != s[j]) continue;
        if (s[i] == '0' && i + 1 < j && s[i + 1] == '0' && s[j - 1] == '0') {
            s[i] = s[j] = '1';
            return s;
        }
    }
    return "-1";
}

int main() {
    mochi;
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (!isValidPalindrome(a, b)) {
            cout << -1 << "\n";
            continue;
        }

        string smallest = buildPalindrome(a, b);
        if (smallest.empty()) {
            cout << -1 << "\n";
            continue;
        }

        string second = secondLexSmallest(smallest);
        cout << second << "\n";
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//