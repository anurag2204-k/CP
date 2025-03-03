//1661B	Getting Zero
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define vll vector<long long>
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define mll map<long long, long long>
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define dd double
#define ll long long int
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define lb lower_bound
#define ub upper_bound
#define se second
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define all(v) (v).begin(), (v).end()
#define nl cout<<"\n"
#define mxe(v)  *max_element(v.begin(),v.end())     
#define mne(v)  *min_element(v.begin(),v.end())    
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));

 
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
 

const int MOD = 1e9 + 7;

void read(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


//third ------------------------------------------------------------------------------------------
void solve(){
    string s; cin>>s;
    int n = s.size();
    int ans[n+1];
    for(int i=0; i<=n; i++){
        ans[i] = 0;
    }
    int last[26];
    for(int i=0; i<26; i++){
        last[i] = 0;
    }

    for(int i= 1; i<=n; i++){
        if(last[s[i-1]-'a']!=0){
            ans[i] = 2 + ans[last[s[i-1]-'a'] - 1];
        }
        ans[i] = max(ans[i], ans[i-1]);
        last[s[i-1]-'a'] = i;
    }
    cout<<n-ans[n];
    nl;

}


//second ------------------------------------------------------------------------------------------

ll dp[200005];

ll fun(ll i, string s){
    if(i >= s.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    if(i == s.size()-1){
        return dp[i] = 1;
    }

    if(i<s.size()-1 and s[i] == s[i+1]){
        return dp[i] = fun(i+2, s);
    }

    ll j;
    for(j=i+1; j<s.size(); j++){
        if(s[j] == s[i]){
            break;
        }
    }
    if(j == s.size()){
        return dp[i] = 1+ fun(i+1, s);
    }
    ll one = 1 + fun(i+1, s);
    ll two = j-i-1 + fun(j+1, s);
    return dp[i] = min(one, two);
}

void solve(){
    string s;
    cin>>s;
    for(ll i = 0; i<s.size(); i++){
        dp[i] = -1;
    }
    ll ans = fun(0, s);
    cout << ans << endl;
}



//one way--------------------------------------------------------------------------------------------

void solve(){
    string s;
        cin>>s;
        map<char,ll>m;
        ll n=s.length();
        ll a=0;
        for(ll j=0;j<n;j++)
        {
            if(m[s[j]])
            {
                a+=2;
                m.clear();
                continue;
            }
            m[s[j]]++;
        }
        cout<<n-a<<"\n";
}




int main() {
    faster();
    
    #ifndef ONLINE_JUDGE
        read();
    #endif
    
    int t;
    cin >> t;
    
    while (t--) 
        solve();

    return 0;
}
