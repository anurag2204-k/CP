
#include <iostream>
#include <vector>
using namespace std;

const int LOG = 20; // Maximum power of 2 we need (since n <= 2*10^5, log2(2*10^5) ≈ 18)
const int N = 200005;

vector<int> adj[N];
int up[N][LOG]; // up[v][j] = 2^j-th ancestor of node v
int depth[N];

// Precompute Binary Lifting Table
void dfs(int node, int parent) {
    up[node][0] = parent; // Direct parent (2^0-th ancestor)
    for (int j = 1; j < LOG; j++) {
        if (up[node][j - 1] != -1)
            up[node][j] = up[up[node][j - 1]][j - 1];
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

// Find LCA using Binary Lifting
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b); // Ensure 'a' is deeper

    // Lift 'a' to the same depth as 'b'
    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j))
            a = up[a][j];
    }

    if (a == b) return a; // If they meet, return as LCA

    // Lift both nodes until they meet at LCA
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0]; // Their parent is the LCA
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Read the tree structure
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    // Initialize up table
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < LOG; j++)
            up[i][j] = -1;

    // Precompute depth and binary lifting table
    depth[1] = 0; // Root at depth 0
    dfs(1, -1);

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}
// ============================






// iterataive approach to find LCA of two nodes in a tree
// Time complexity: O(nlogn) for preprocessing and O(logn) for each query
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, depth;
vector<vector<int>> up, tree;

void preprocess(int n) {
    int LOG = 0;
    while ((1 << LOG) <= n) LOG++;

    up.assign(n + 1, vector<int>(LOG, -1));
    depth.assign(n + 1, 0);

    // Direct parent (2^0-th ancestor)
    for (int i = 2; i <= n; i++) {
        up[i][0] = parent[i];
    }

    // Compute depth using BFS (Optimized)
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : tree[node]) {
            depth[child] = depth[node] + 1;
            q.push(child);
        }
    }

    // Compute Binary Lifting Table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
}

// Iterative function to find LCA
int findLCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b); // Ensure 'a' is deeper

    int LOG = up[0].size();

    // Bring 'a' to same depth as 'b'
    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) return a; // Already LCA

    // Move both up until they meet
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return parent[a]; // The parent of both is LCA
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.assign(n + 1, -1);
    tree.assign(n + 1, vector<int>());

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        tree[parent[i]].push_back(i);  // Store child nodes
    }

    preprocess(n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << findLCA(a, b) << "\n";
    }

    return 0;
}
