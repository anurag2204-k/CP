#include <bits/stdc++.h>
using namespace std;

const int LOG = 20; // Assuming at most 2^20 depth
const int N = 1e5 + 5;
vector<int> adj[N];
int up[N][LOG]; // up[v][j] = 2^j-th ancestor of node v
int depth[N];

void dfs(int node, int parent) {
    up[node][0] = parent; // Immediate parent
    for (int j = 1; j < LOG; j++) {
        if (up[node][j - 1] != -1)
            up[node][j] = up[up[node][j - 1]][j - 1]; // 2^j-th ancestor
        else
            up[node][j] = -1;
    }
    for (int child : adj[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int get_kth_ancestor(int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) break;
        }
    }
    return node;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    u = get_kth_ancestor(u, diff);

    if (u == v) return u;

    // Lift both u and v together
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0]; // Parent of u (or v) is LCA
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(up, -1, sizeof(up));
    depth[0] = 0;
    dfs(0, -1); // Rooting the tree at node 0

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is: " << LCA(u, v) << endl;
    }
    
    return 0;
}


// trial ============================================ iterative way 

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20; // Max log value for N ~ 10^5
const int N = 1e5 + 5;
vector<int> adj[N];
int up[N][LOG]; // up[v][j] = 2^j-th ancestor of node v
int depth[N];

void preprocess(int root, int n) {
    memset(up, -1, sizeof(up));
    stack<pair<int, int>> stk; // (node, parent)
    stk.push({root, -1});
    depth[root] = 0;

    while (!stk.empty()) {
        auto [node, parent] = stk.top();
        stk.pop();

        up[node][0] = parent; // Immediate parent
        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[up[node][j - 1]][j - 1]; // 2^j-th ancestor
        }

        for (int child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                stk.push({child, node});
            }
        }
    }
}

int get_kth_ancestor(int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) break;
        }
    }
    return node;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // Move u to the same depth as v
    u = get_kth_ancestor(u, depth[u] - depth[v]);

    if (u == v) return u;

    // Lift both nodes up together
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0]; // Parent of u (or v) is LCA
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preprocess(0, n); // Root at node 0

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is: " << LCA(u, v) << endl;
    }

    return 0;
}


// parent array given

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;  // log2(2 * 10^5) ≈ 17, using 20 for safety
const int N = 200005;
int up[N][LOG];  // up[i][j] = 2^j-th boss of employee i
int depth[N];    // depth[i] = depth of employee i

void preprocess(int n, vector<int>& parent) {
    memset(up, -1, sizeof(up));  // Initialize table with -1 (no ancestor)

    // Base case: 2^0-th ancestor (direct boss)
    for (int i = 2; i <= n; i++) {
        up[i][0] = parent[i - 2];  // Employee i's direct boss
        depth[i] = depth[parent[i - 2]] + 1;  // Compute depth
    }

    // Fill the DP table for binary lifting
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];  // Jump to 2^j-th boss
            }
        }
    }
}

// Function to lift node x up by k levels
int lift(int x, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {  // If j-th bit is set, move up 2^j levels
            x = up[x][j];
            if (x == -1) return -1;  // No further boss available
        }
    }
    return x;
}

// Function to find LCA of u and v
int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);  // Ensure u is deeper

    // Step 1: Move u up to the same depth as v
    u = lift(u, depth[u] - depth[v]);

    if (u == v) return u;  // Found LCA

    // Step 2: Move u and v up together until they meet
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    // Step 3: Their parent is the LCA
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> parent[i];
    }

    preprocess(n, parent);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << findLCA(u, v) << '\n';
    }

    return 0;
}
