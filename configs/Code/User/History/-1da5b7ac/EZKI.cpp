#include <iostream>
#include <string>

// Helper function to replace all occurrences of 'from' with 'to' in 'str'
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty()) return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Move past the replacement
    }
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); // Ignore the newline after the number of test cases
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        replaceAll(s, "FFT", "FTF");
        replaceAll(s, "NTT", "TNT");
        std::cout << s << std::endl;
    }
    return 0;
}