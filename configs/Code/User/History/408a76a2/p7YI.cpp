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

// g++ -o mochi mochi.cpp && ./mochi
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

#include <bits/stdc++.h>
using namespace std;

// دالة لتكوين أصغر palindrome
string smallest_palindrome(int a, int b) {
    int n = a + b;
    string res(n, ' ');
    int l = 0, r = n - 1;
    while (l < r) {
        if (a >= 2) {
            res[l] = res[r] = '0';
            a -= 2;
        } else if (b >= 2) {
            res[l] = res[r] = '1';
            b -= 2;
        } else {
            return "-1";
        }
        l++; r--;
    }
    if (l == r) {
        if (a == 1) res[l] = '0';
        else if (b == 1) res[l] = '1';
        else return "-1";
    }
    if (a == 0 && b == 0) return res;
    return "-1";
}

// دالة لإيجاد ثاني أصغر palindrome
string second_palindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) return "-1"; // ليس palindrome أصلاً
    }
    // حاول تبديل أول موضعين بحيث تظل palindrome وتكون أكبر
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] == '0' && s[n - 1 - i] == '0') continue;
        if (s[i] == '0' && s[n - 1 - i] == '1') {
            // جرب تبديلهما إلى '1' و '0'
            string t = s;
            t[i] = t[n - 1 - i] = '1';
            // تحقق أن عدد الآحاد والأصفار صحيح
            int zeros = count(t.begin(), t.end(), '0');
            int ones = count(t.begin(), t.end(), '1');
            if (zeros + ones == n) return t;
        }
    }
    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s = smallest_palindrome(a, b);
        if (s == "-1") {
            cout << -1 << '\n';
            continue;
        }
        // جرب إيجاد الثاني
        string ans = "-1";
        int n = s.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            if (s[i] == '0' && s[n - 1 - i] == '0' && b >= 2) {
                // جرب تبديلهما إلى '1'
                string t = s;
                t[i] = t[n - 1 - i] = '1';
                int zeros = count(t.begin(), t.end(), '0');
                int ones = count(t.begin(), t.end(), '1');
                if (zeros == a - 2 && ones == b + 2) {
                    ans = t;
                    break;
                }
            }
        }
        if (ans == "-1") {
            // جرب الطريقة العامة
            ans = s;
            bool found = false;
            for (int i = n / 2 - 1; i >= 0; --i) {
                if (ans[i] == '0' && ans[n - 1 - i] == '0') {
                    ans[i] = ans[n - 1 - i] = '1';
                    int zeros = count(ans.begin(), ans.end(), '0');
                    int ones = count(ans.begin(), ans.end(), '1');
                    if (zeros + ones == n) {
                        found = true;
                        break;
                    }
                    ans[i] = ans[n - 1 - i] = '0';
                }
            }
            if (!found) ans = "-1";
        }
        cout << ans << '\n';
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//