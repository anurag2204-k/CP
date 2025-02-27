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
    int n, m;
    cin>>m>>n;
    if(n==1){
        cout<<0<<endl;
    }else if(m==1){
        cout<<2<<endl;
    }else if(n>m){
        cout<<m+1<<endl;
    }else{
        cout<<min(n,m)<<endl;
    }
    for(int i=0; i<m; i++){
        int begining = (i+1)%n == 0 ? 1 : (i+1)%n;
        for(int j = 0; j<n ;j++){
            cout<< (begining + j)%(n)<<" ";
        }
        cout<<endl;
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