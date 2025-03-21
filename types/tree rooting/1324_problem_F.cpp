#include <bits/stdc++.h>
using namespace std;

#define ll int 

void dfs1(int node, int par, vector<ll> &maxi, vector<int> &color, vector<vector<int>> &adj) {
    maxi[node] = (color[node] == 1) ? 1 : -1;
    
    for (auto child : adj[node]) {
        if (child != par) {
            dfs1(child, node, maxi, color, adj);
            maxi[node] += max(0, maxi[child]); // Only add positive values
        }
    }
}

void dfs2(int node, int par, vector<ll> &maxi, vector<int> &color, vector<vector<int>> &adj, vector<ll> &ans) {
    ans[node] = maxi[node];

    for (auto child : adj[node]) {
        if (child == par) continue;

        ll old_par = maxi[node];
        ll old_child = maxi[child];

        maxi[node] -= max(0, maxi[child]); // Remove child's contribution
        maxi[child] += max(0, maxi[node]); // Add updated parent contribution

        dfs2(child, node, maxi, color, adj, ans);

        maxi[node] = old_par;
        maxi[child] = old_child;
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> color(n + 1);
    
    for (int i = 1; i <= n; i++) 
        cin >> color[i];

    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> maxi(n + 1, 0);
    dfs1(1, 0, maxi, color, adj);

    vector<ll> ans(n + 1, 0);
    dfs2(1, 0, maxi, color, adj, ans);

    for (int i = 1; i <= n; i++) 
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
