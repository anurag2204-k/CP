#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubstring(string s) {
    int n = s.length();
    if (n == 0) return 0;
    
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    int start = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }
    
    cout << "Longest palindromic substring: " << s.substr(start, maxLength) << endl;
    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of longest palindromic substring: " << longestPalindromeSubstring(s) << endl;
    return 0;
}
