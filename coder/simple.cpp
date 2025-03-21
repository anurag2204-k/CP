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
