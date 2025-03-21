// Counting Strings
// Read problems statements in Mandarin Chinese, Russian and Vietnamese as well.
// You are given a string s consisting of upper case Latin alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings t with length equal to that of S, also consisting of upper case Latin alphabet are there satisfying the following conditions:

// String t is lexicographical larger than s
// When you write both s and t in the reverse order, t is still lexicographical larger than s.
// Find out number of such strings t. As the answer could be very large, output it modulo 109 + 7

// Input
// The only line of input contains string s.

// Output
// Output a single line containing an integer corresponding to the result in modulo 109 + 7.

// Constraints
// 1 ≤ |S| ≤ 105
// Example
// Input 1:
// ZAZ
// Output 1:
// 25


// Input 2:
// XYZ


// Output 2:
// 5

// Explanation
// Test #1: To make a valid string t, you can just replace the letter A in S by any other letter, e.g. by replacing 'A' by 'B', we get t = ZBZ. Note that ZBZ is lexicographically larger than ZAZ. Reverse of t (i.e. ZBZ) is also lexicographically larger than reverse of s (i.e. ZAZ).

// Test #2: there are 5 valid strings: YYZ, ZYZ, XZZ, YZZ, ZZZ


#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long int lli;

lli dp[100010][4][4];
int len;
string s;

lli solve(int idx, int ub1, int ub2) {
    if (idx >= len) return (ub1 && ub2) ? 1 : 0;
    if (dp[idx][ub1][ub2] != -1) return dp[idx][ub1][ub2];

    lli ans = 0;

    if (ub1 == 0) {
        for (char i = s[idx]; i <= 'Z'; i++) {
            if (s[idx] < i)
                ans = (ans + solve(idx + 1, 1, 1)) % mod;
            else
                ans = (ans + solve(idx + 1, 0, ub2)) % mod;
        }
    } else {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (s[idx] < i)
                ans = (ans + solve(idx + 1, 1, 1)) % mod;
            else if (s[idx] > i)
                ans = (ans + solve(idx + 1, 1, 0)) % mod;
            else
                ans = (ans + solve(idx + 1, 1, ub2)) % mod;
        }
    }

    return dp[idx][ub1][ub2] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    len = s.length();
    
    lli ans = solve(0, 0, 0);
    cout << ans << endl;

    return 0;
}