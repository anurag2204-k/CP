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

#ifndef ONLINE_JUDGE
    #include "test.cpp"
#endif

void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    cin >> a;

    int cur = a[0];
    bool flip = true;
    ll total = 0;
    f(i, 1, n){
        if(flip){
            if(a[i]>a[i-1]){
                cur = a[i];
            }else{
                total += cur;
                cur = a[i];
                flip = !flip;
            }
        }else{
            if(a[i]<a[i-1]){
                cur = a[i];
            }else{
                total -= cur;
                cur = a[i];
                flip = !flip;
            }
        }
    }
    if(flip){
        total += cur;
    }

    cout << total; nl;
}
    


int main() {
    faster();
    
    #ifndef ONLINE_JUDGE
        read();
    #endif
    
    ll t;
    cin >> t;
    
    while (t--) 
        solve();


    #ifndef ONLINE_JUDGE
        test_main(); 
        cout<<"\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}

