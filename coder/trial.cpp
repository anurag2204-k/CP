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

const int N = 100'000;

void solve(){int n=1,k=0;
    string s;
    cin>>n;
    vi v(n);
    int prev=0;
    cin>>v;
    vi a(n,0),b(n,0);
    unordered_set<int> as,bs;
    for(int i=0;i<n;i++){
        if(!as.count(v[i])){
            as.insert(v[i]);
            a[i]=v[i];
        }
        else if(!bs.count(v[i])){
            bs.insert(v[i]);
            b[i]=v[i];
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    set<int> rema,remb;
    for(int i=1;i<=n;i++){
        if(!as.count(i))    rema.insert(i);
        if(!bs.count(i))    remb.insert(i);
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            auto it=rema.upper_bound(b[i]);
            if(it==rema.begin()){
                cout<<"NO\n";
                return;
            }
            --it;
            a[i]=*it;
            rema.erase(it);
        }
        if(b[i]==0){
            auto it=remb.upper_bound(a[i]);
            if(it==remb.begin()){
                cout<<"NO\n";
                return;
            }
            it--;
            b[i]=*it;
            remb.erase(it);
        }
    }
    cout<<"YES\n";
    cout<<a<<" \n";
    cout<<b<<" \n";
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


    #ifndef ONLINE_JUDGE
        test_main(); 
        cout<<"\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}
