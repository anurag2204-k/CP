#include <bits/stdc++.h>
using namespace std;

void solve(int node, int par, vector<int>& ans, vector<vector<int>>& dp, vector<vector<int>>& adj) {
    int max1 = 0, max2 = 0;
    for (auto child : adj[node]) {
        if (child != par) {
            solve(child, node, ans, dp, adj);
            int val = dp[child][0];  // Max depth from child
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else {
                max2 = max(max2, val);
            }
        }
    }
    dp[node][0] = max1 + 1;
    dp[node][1] = max2 + 1;
}

void dfs(int node, int par, vector<int>& ans, vector<vector<int>>& dp, vector<vector<int>>& adj) {
    ans[node] = max(dp[node][0], dp[node][1]);

    for (auto child : adj[node]) {
        if (child == par) continue;

        int old_dp_node_0 = dp[node][0], old_dp_node_1 = dp[node][1];
        int old_dp_child_0 = dp[child][0], old_dp_child_1 = dp[child][1];

        // If the max path to `node` passes through `child`, update child accordingly
        
        if(dp[node][0] == dp[child][0]+1){
            dp[child][1] = max(dp[child][1], dp[node][1]+1);
        }else if(dp[node][0] > dp[child][0]){
            dp[child][0] = dp[node][0] + 1;
            dp[child][1] = max(dp[child][1], dp[node][1]+1);
        }

        dfs(child, node, ans, dp, adj);

        // Restore old dp values
        dp[node][0] = old_dp_node_0;
        dp[node][1] = old_dp_node_1;
        dp[child][0] = old_dp_child_0;
        dp[child][1] = old_dp_child_1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    vector<int> ans(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, 0, ans, dp, adj);
    dfs(1, 0, ans, dp, adj);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << " ";  // Output eccentricity of each node
    }
    cout << endl;

    return 0;
}
