#include <bits/stdc++.h>
using namespace std;

int solver(string s, string t, int i, int j, vector<vector<int>>dp){
    if(i==s.size() || j==t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = 1 + solver(s, t, i+1, j+1, dp);
    }
    return dp[i][j] = max(solver(s, t, i+1, j, dp), solver(s, t, i, j+1, dp));
}

int main(){
    string s; 
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    string t = s;
    reverse(t.begin(), t.end());

    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(s[i] == t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n ;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][0];
    return 0;
}