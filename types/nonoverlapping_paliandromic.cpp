#include <iostream>
#include <vector>
using namespace std;

vector<string> extractPalindromicDecomposition(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<string> result;
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    
    int i = 0;
    while (i < n) {
        for (int j = n - 1; j >= i; j--) {
            if (dp[i][j]) {
                result.push_back(s.substr(i, j - i + 1));
                i = j + 1;
                break;
            }
        }
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    vector<string> palindromicDecomposition = extractPalindromicDecomposition(s);
    
    cout << "Palindromic decomposition: ";
    for (const string& p : palindromicDecomposition) {
        cout << p << " ";
    }
    cout << endl;
    
    return 0;
}
