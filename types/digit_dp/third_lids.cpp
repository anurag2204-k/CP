// We all know about LIS (Longest Increasing Sub sequence). The task to find the length of the longest increasing sub sequence in a given array of
// integers is very easy. For example, the length of the LIS for {15, 27, 14, 38, 26, 55, 46, 65, 85} is 6 and the longest increasing sub sequence is
// {15, 27, 38, 55, 65, 85}.
// But do we all know about LIDS? The task to find the length of the longest increasing digit sub sequence within an integer is known as LIDS. For
// example, length of LIDS for 1234 is 4, length of LIDS for 12234 is 4, length of LIDS for 456123 is 3.{7}, {I, 4, 9}, {5, 9} are some valid increasing
// digit sequence while {3, 2}, {I, I}, {4, 9, I} are invalid.
// You are given two integers x and y. You have to answer maximum length of LIDS between x and y inclusive and the number of different ways
// maximum LIDS can be formed. Two ways are considered different if the longest increasing digit sequence are not same or they are chosen from
// different position in an integer.
// Input
// Input starts with an integer T (T < 10000), denoting the number of test cases. Each of the test cases consists of two space separated integers X and
// y denoting the range.
// Easy subtask: 1 < y < 1000
// Medium subtask: 1 y 1000, 000, 000 and (y —
// Hard subtask: I C y 1000, 000,
// Digits are: O, 1, 2, 3, 45, 67, 8 and 9.
// c) 1000
// Output
// For each of the test cases, you need to print one line of output. The output for each test case starts with the test case number, followed by Maximum Length of LIDS and the number of ways LIDS can be formed. You must output as it is given in the sample output section.

// Sample
// Input	Output
// 2
// 111 114
// 15432  15432
// Case 1: 2 6
// Case 2: 2 4

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> digits;
int dp[11][2][10];  // DP State

int digitDp(int ind, bool tight, int prev) {
    if (ind == digits.size()) {
        return 1;
    }
    
    if (dp[ind][tight][prev] != -1) {
        return dp[ind][tight][prev];
    }
    
    int limit = tight ? digits[ind] : 9;
    int ans = 0;

    for (int i = prev; i <= limit; i++) { // Ensure non-decreasing order
        bool newTight = (tight && i == limit);
        ans += digitDp(ind + 1, newTight, i);
    }

    return dp[ind][tight][prev] = ans;
}

int digiter(int n) {
    if (n < 0) return 0;  // Edge case for negative numbers

    digits.clear();
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    
    reverse(digits.begin(), digits.end());
    
    memset(dp, -1, sizeof(dp));
    
    return digitDp(0, true, digits[0]); // prev is initialized to 0, not false
}

int32_t main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        cout << "Case " << i << ": " << digiter(y) - digiter(x - 1) << endl;
    }
    
    return 0;
}
