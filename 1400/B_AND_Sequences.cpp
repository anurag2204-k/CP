#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAX_N = 200005;  // Maximum possible value of n

// Precompute factorials and modular inverses using Fermat's Little Theorem
int fact[MAX_N], inv_fact[MAX_N];

// Fast modular exponentiation: x^y % p
int power(int x, int y, int p) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

// Precompute factorials and modular inverses
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2, MOD);
    for (int i = MAX_N - 2; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// Solve function
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_and = (1LL << 31) - 1;  // Initialize with all 1s in 32-bit range
    for (int &x : a) {
        cin >> x;
        total_and &= x;
    }

    // Count how many numbers are equal to `total_and`
    int cnt = count(a.begin(), a.end(), total_and);

    // If cnt < 2, it's impossible to form a valid permutation
    if (cnt < 2) {
        cout << 0 << "\n";
        return;
    }

    // Compute answer using (cnt * (cnt-1) * (n-2)!) % MOD
    int ans = (cnt * (cnt - 1)) % MOD;
    ans = (ans * fact[n - 2]) % MOD;

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();  // Precompute factorials and inverse factorials

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
