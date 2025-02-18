#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), da(n,-1), db(n,-1);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    
    // Base case
    da[0] = a[0];
    db[0] = b[0];
    
    // Fill DP arrays matching recursive logic exactly
    for(int i=1; i<n; i++) {
        for(int j=0; j<2; j++) {
            // Not take - stay in same array
            int nt;
            if(j == 0) nt = da[i-1];
            else nt = db[i-1];
            
            // Take current and switch array
            int t;
            if(j == 0) {
                t = a[i] + db[i-1];  // Take from a[i], add best from previous b
            } else {
                t = b[i] + da[i-1];  // Take from b[i], add best from previous a
            }
            
            // Store the maximum
            if(j == 0) da[i] = max(nt, t);
            else db[i] = max(nt, t);
        }
    }
    
    cout << max(da[n-1], db[n-1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}