/*
    In a simple number game, two players each choose a number. The player
    with the smaller number loses the game. If both players choose the same
    number, the game ends in a draw. Your task is to determine the outcome:
    who loses the game, or if it's a draw.
    Input
    The first line contains an integer , representing the
    number chosen by the first player.
    The second line contains an integer , representing the
    number chosen by the second player.
    Output
    Output a single line with one of the following:
    "p1" if the first player loses,
    "p2" if the second player loses,
    "d" if the game is a draw.
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

signed main() {
    mochi;
    int x_x = 1;
    // cin >> x_x;
    while (x_x --> 0) {
        int p1, p2;
        cin >> p1 >> p2;
        if (p1 > p2) {
            cout << "p1";
        }
    }
    return 0;
}
//-------------------------------------Ende-----------------------------------------//