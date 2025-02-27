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
#define dd double
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
 
#define ll long long int
#define pb push_back
// #define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define mp make_pair
#define in insert
#define fi first
// #define lb lower_bound
#define ub upper_bound
#define se second
#define all(v) (v).begin(), (v).end()
const int MOD = 1e9 + 7;
 
 
void read(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
 
// int main() {
//     read();
//     faster();
//     // Your code here
 
 
    
//     return 0;
 
// }
 
const int N = 100'000;
 
void solve(){
    int n; 
    cin>>n;
    vll a(n);
    f(i, 0, n) cin>>a[i];
    vector<bool> b(n+1, false);
    f(i, 0, n){
        if(a[i]<=n)
        b[a[i]]=true;
    }
    ll mex = 0;
    f(i, 0, n+1){
        if(b[i]==false){
            mex = i;
            break;
        }
    }
    ll mex2 = mex+1;
    int left = 0, right = n-1;
    f(i, 0, n){
        if(a[i]==mex2)
        {
            left = i;
            break;
        }
    }
    f(i, n-1, 0){
        if(a[i]==mex2){
            right = i;
            break;
        }
    }
    f(i, 0, n){
        b[i] = false;
    }
    f(i,0,left){
        if(a[i]<=n)
        b[a[i]]=true;
    }
    f(i, right+1, n){
        if(a[i]<=n)
        b[a[i]]=true;
    }
    ll mex3 = 0;
    f(i, 0, n+1){
        if(b[i]==false){
            mex3 = i;
            break;
        }
    }
    cout<<left<<" "<<right<<endl;
    if(mex3==mex){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
 
 
 
int main() {
    faster();
    #ifndef ONLINE_JUDGE
        read();
    #endif
    
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}