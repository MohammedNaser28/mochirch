#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int increase_count = 0;
    int last_increase = -1;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] < b[i + 1]) {
            increase_count++;
            last_increase = i;
        }
    }
    bool possible = true;
    if (increase_count > 1) {
        possible = false;
    } else if (increase_count == 1) {
        // Check if the array is non-increasing after last_increase + 1
        for (int i = last_increase + 1; i < n - 1; i++) {
            if (b[i] < b[i + 1]) {
                possible = false;
                break;
            }
        }
    }
    // If no increases, the array must be non-increasing, already checked implicitly
    cout << (possible ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}