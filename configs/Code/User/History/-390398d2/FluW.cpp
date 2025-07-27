#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int x = 0;  // Initial value of x is 0
    
    for (int i = 0; i < n; i++) {
        string statement;
        cin >> statement;
        
        // Check if the statement contains "++" or "--"
        if (statement.find("++") != string::npos) {
            x++;  // Increment operation
        } else if (statement.find("--") != string::npos) {
            x--;  // Decrement operation
        }
    }
    
    cout << x << endl;
    
    return 0;
}
