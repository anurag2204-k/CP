// An integer is divisible by 3 if the sum of its digits is also divisible by 3. For example, 3702 is divisible by 3 and 12 (3+7+0+2) is also divisible by 3. This property also holds for the integer 9.

// In this problem, we will investigate this property for other integers.

// Input
// Input starts with an integer T (≤ 200), denoting the number of test cases.

// Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000)>.

// Output
// For each case, output the case number and the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.

// Sample
// Input	Output
// 3
// 1 20 1
// 1 20 2
// 1 1000 4

// Case 1: 20
// Case 2: 5
// Case 3: 64
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[10][2][100][100];
lli val;

lli ch(string s) {
    lli num = 0, sum = 0;
    for (int i = 0; i < s.length(); i++) {
        num = num * 10 + s[i] - '0';
        sum += s[i] - '0';
    }
    return (num % val == 0 && sum % val == 0);
}

lli solve(lli idx, bool tight, lli num, string s, lli n, lli sum) {
    if (idx >= n) {
        return (num % val == 0 && sum % val == 0);
    }
    
    if (dp[idx][tight][num][sum] != -1)
        return dp[idx][tight][num][sum];
        
    lli ret = 0;
    if (tight == 1) {
        for (int i = 0; i <= s[idx] - '0'; i++) {
            lli numm = num * 10 + i;
            lli summ = sum + i;
            if (i == s[idx] - '0')
                ret += solve(idx + 1, 1, numm % val, s, n, summ);
            else
                ret += solve(idx + 1, 0, numm % val, s, n, summ);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            lli numm = num * 10 + i;
            lli summ = sum + i;
            ret += solve(idx + 1, 0, numm % val, s, n, summ);
        }
    }
    dp[idx][tight][num][sum] = ret;
    return ret;
}

int main() {
    lli t;
    cin >> t;
    lli cas = 1;
    while (t--) {
        string l, r;
        cin >> l >> r >> val;
        
        // If val is 100 or more, no number in the given range can have its digit sum divisible by val.
        if (val >= 100) {
            cout << "Case " << cas++ << ": " << 0 << endl;
            continue;
        }
        
        memset(dp, -1, sizeof(dp));
        lli ans1 = solve(0, 1, 0, r, r.length(), 0);
        
        memset(dp, -1, sizeof(dp));
        lli ans2 = solve(0, 1, 0, l, l.length(), 0);
        
        // Adjust for inclusive lower bound
        if (ch(l))
            ans1++;
        
        cout << "Case " << cas++ << ": " << ans1 - ans2 << endl;
    }
    return 0;
}
