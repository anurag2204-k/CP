#include <bits/stdc++.h>
using namespace std;


int dp[12][2]; // DP table (max 10^5, so 12 digits)
vector<int> digits;

// Function to compute count using digit DP
int digitDP(int pos, bool tight, bool hasPrettyLast) {
    if (pos == digits.size()) // If we reach the end
        return hasPrettyLast; // Count only if it has a valid last digit
    
    if (dp[pos][tight] != -1) return dp[pos][tight];

    int limit = tight ? digits[pos] : 9; // Digit bound if tight, else 9
    int ans = 0;

    for (int d = 0; d <= limit; d++) {
        bool newTight = (tight && d == limit);
        bool newPrettyLast = hasPrettyLast || (pos == digits.size() - 1 && (d == 2 || d == 3 || d == 9));
        ans += digitDP(pos + 1, newTight, newPrettyLast);
    }

    return dp[pos][tight] = ans;
}

// Function to count pretty numbers up to R
int countPrettyNumbers(int R) {
    if (R == 0) return 0; // Edge case

    digits.clear();
    while (R > 0) {
        digits.push_back(R % 10);
        R /= 10;
    }
    reverse(digits.begin(), digits.end());

    memset(dp, -1, sizeof(dp));
    return digitDP(0, true, false);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << countPrettyNumbers(R)  << endl;
    }
    return 0;
}
