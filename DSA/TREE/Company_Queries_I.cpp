#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;  // log2(2 * 10^5) ≈ 17, use 20 for safety
const int N = 200005;
int up[N][LOG];  // up[i][j] = 2^j-th boss of employee i

void preprocess(int n, vector<int>& boss) {
    // Initialize the up table
    memset(up, -1, sizeof(up));

    // Fill the base case: the direct boss (2^0-th ancestor)
    for (int i = 2; i <= n; i++) {
        up[i][0] = boss[i - 2];  // boss[i-2] is given for employee i
    }

    // Fill the DP table for binary lifting
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];  // Move to the 2^j-th boss
            }
        }
    }
}

int getKthBoss(int x, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {  // If j-th bit is set, move up 2^j levels
            x = up[x][j];
            if (x == -1) return -1;  // No further boss available
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> boss(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> boss[i];
    }

    preprocess(n, boss);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << getKthBoss(x, k) << '\n';
    }

    return 0;
}
////////////////////////trial ============================================

// Binary Lifting tutorial https://youtu.be/oib-XsjFa-M
class TreeAncestor {
    vector<vector<int>> up; // int up[N][20];
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        // up[v][j] is 2^j -th ancestor of node v
        parent[0] = 0;
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];
            if(v != 0) {
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = LOG - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};