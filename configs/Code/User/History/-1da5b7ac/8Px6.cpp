// g++ -o mochi mochi.cpp && ./mochi
// Created by HP on 2025-07-15 06:07:00
// ----------------> practice makes perfect <----------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define mochi                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define infile freopen("input.txt", "r", stdin);
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

void pewpew()
{
  string s;
  cin >> s;
  map<char, int> freq;
  for (auto c : s)
  {
    freq[c]++;
  }
  string ans = "";
  while (freq['T']) {
    ans.push_back('T');
    freq['T']--;
  }
  while (freq['N']) {
    ans.push_back('N');
    freq['N']--;
  }
  while (freq['F']) {
    ans.push_back('F');
    freq['F']--;
  }
  for (auto [key, fr] : freq) {
    while (fr) {
      ans.push_back(key);
    freq[key]--;
    }
  }
  
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