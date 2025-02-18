#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int NMAX = 200005;

vector<long long> power2(NMAX, 1), invPower2(NMAX, 1);

void precompute_powers() {
    long long inv2 = 499122177; // Modular inverse of 2 mod MOD
    for (int i = 1; i < NMAX; i++) {
        power2[i] = (power2[i - 1] * 2) % MOD;
        invPower2[i] = (invPower2[i - 1] * inv2) % MOD;
    }
}

void solve() {
    precompute_powers();
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long result = 0, sumOnes = 0;
    int count1 = 0, count2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            sumOnes = (sumOnes + invPower2[count2]) % MOD;
            count1++;
        } else if (a[i] == 2) {
            count2++;
        } else if (a[i] == 3) {
            long long contrib = ((power2[count2] * sumOnes) % MOD - count1 + MOD) % MOD;
            result = (result + contrib) % MOD;
        }
    }
    
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}