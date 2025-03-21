// Vasya likes the number 239. Therefore, he considers a number prettyif its last digit is 2.3 or 9.
// Vasya wants to watch the numbers between L and R (both inclusive), so he asked you to determine
// how many pretty numbers are in this range. Can you help him?
// Input
// • The first line of the input contains a single integer T denoting the number of test cases. The
// description of T test cases follows.
// • The first and only line of each test case contains two space-separated integers L and R.

// first

#include <bits/stdc++.h>
using namespace std;

/////// first -------------------------------------------------------------------------------------------

// int main(){
//     int l, r;
//     cin>>l>>r;
//     int ans = 0;
//     for(int i=l; i<=r; i++){
//         if(i%10==2 || i%10==3 || i%10==9){
//             ans++;
//         }
//     }
//     cout<<ans;
// }



/////////second -----------------------------------------------------------------------------------------
vector<int> digits;
int dp[12][2];
int digitDp(int i, bool tight, bool isPreety){
    if(i==digits.size()){
        return isPreety;
    }
    if(dp[i][tight]!=-1){
        return dp[i][tight];
    }

    int limit =  tight ? digits[i] : 9;
    int ans = 0;
    for(int d=0; d<=limit; d++){
        bool newtight = (tight && d==limit);
        bool newPreety = i==digits.size()-1 && (d==2 || d==3 || d==9);
        ans += digitDp(i+1, newtight, newPreety);
    }
    return dp[i][tight] = ans;
}

int digiter(int n){
    digits.clear();
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));
    return digitDp(0, true, false);
}

int main(){
    int t; 
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        cout<< digiter(r) - digiter(l-1);
    }
}