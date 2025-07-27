/*
    Wu-Tang is a highly skilled kung fu player capable of using his head, legs,
    or arms in combat. One day, he found himself trapped in a cave filled with
    monsters that he must defeat in a specific order. Each monster has a
    strength denoted as , and Wu-Tang can choose to attack using one of
    three methods: head, legs, or arms, which inflict , , and damage,
    respectively.
    However, Wu-Tang must follow a strict rule: for each monster, he can
    choose only one method to attack, but he cannot use the same method
    consecutively for the next monster. This means if he defeats a monster
    using his head, the next monster cannot be attacked with his head again,
    but must be attacked with either his legs or arms.
    The objective is for Wu-Tang to defeat all the monsters in the minimum
    number of hits while adhering to this rule.
    
    Input
    The first line of the input contains four integers
        — the number of monsters, the
        amount of damage for head, leg, arm, respectively.
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
#define mochi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

void pewpew() {
    int n, h, l, a;
    cin >> n >> h >> l >> a;
    ll arr[n];
    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }

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