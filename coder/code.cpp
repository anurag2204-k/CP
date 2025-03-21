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
#define nl cout << "\n"
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())))

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.fi >> a.se; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.fi << ' ' << a.se; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; f(i, 1, n) cout << ' ' << a[i]; return cout; }
// ===================================END Of the input module ==========================================

const int MOD = 1e9 + 7;

void read() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void faster() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifndef ONLINE_JUDGE
#include "test.cpp"
#endif

const int N = 100'000;
#define MAX_N 100
#define MAX_M 100

void dfs1(int node, int par, vll &maxi, vi &color, vector<vector<int>> &adj){
    maxi[node] = 1LL*color[node];
    for(auto child: adj[node]){
        if(child != par){
            dfs1(child, node, maxi, color, adj);
            maxi[node] = max(maxi[node], maxi[node] + maxi[child]);
        }
    }
    return;
}

void dfs(int node, int par, vll &maxi, vi &color, vector<vector<int>> &adj, vll &ans){
    ans.pb(maxi[node]);
    for(auto child: adj[node]){
        if(child == par) continue;

        ll old_par = maxi[node];
        ll old_child = maxi[child];

        maxi[node] = max(color[node], maxi[node] - maxi[child]);
        maxi[child] = max(maxi[child], maxi[child] + maxi[node]);

        dfs(child, node, maxi, color, adj, ans);

        maxi[node] = old_par;
        maxi[child] = old_child;
    }
}


void solve(){
    int n; cin>>n;
    vi color(n+1);
    f(i, 1, n+1)cin>>color[i];

    vector<vector<int>> adj(n+1);
    f(i, 0, n-1){
        int u, v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vll maxi(n+1, 0);
    dfs1(1, 0, maxi, color, adj);

    vll ans ;

    dfs(1, 0, maxi, color, adj, ans);

    cout<<ans;nl;
}

int main() {
    faster();

    #ifndef ONLINE_JUDGE
    read();
    #endif

    int t;t = 1;
    // cin >> t;

    while (t--)
        solve();

    #ifndef ONLINE_JUDGE
    test_main();
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}
