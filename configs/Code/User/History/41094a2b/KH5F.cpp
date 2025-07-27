/*
    Jack is organizing his schedule and needs to determine if the day of the
    month he picks is for work or rest. He considers even-numbered days as
    workdays and odd-numbered days as rest days.
    Help Jack by writing a program that determines if a given day number is a
    workday or a rest day.
    Input
    A single integer representing the day of the month (1 to 31).
    Output
    Print "Work" if the day is a workday.
    Print "Rest" if the day is a rest day.
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

void pewpew() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "Rest";
        return;
    }
    cout << "Work";
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