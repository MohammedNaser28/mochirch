#include <iostream>
#include <vector>
using namespace std;

// Function to return the prime factors of n as a vector of pairs (prime, exponent)
vector<pair<int, int>> prime_factors(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            ++count;
        }
        if (count > 0) {
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

int main() {
    for (int num = 1; num <= 1000; ++num) {
        cout << num << " = ";
        if (num == 1) {
            cout << "1";
        } else {
            vector<pair<int, int>> factors = prime_factors(num);
            for (size_t i = 0; i < factors.size(); ++i) {
                cout << factors[i].first;
                if (factors[i].second > 1)
                    cout << "^" << factors[i].second;
                if (i + 1 < factors.size())
                    cout << " * ";
            }
        }
        cout << endl;
    }
    return 0;
}