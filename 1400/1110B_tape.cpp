#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define f(i,a,b) for(ll i=a;i<b;i++)
#define nl "\n"

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vll b(n);
    f(i,0,n) cin >> b[i];

    vll gaps;
    f(i,1,n) {
        gaps.push_back(b[i] - b[i-1] - 1);  // Gaps between broken segments
    }

    sort(gaps.rbegin(), gaps.rend());  // Sort in descending order to pick largest k-1 gaps

    ll total_length = b[n-1] - b[0] + 1;  // Initial tape covering all broken segments
    f(i,0,k-1) {
        total_length -= gaps[i];  // Reduce the largest gaps
    }

    cout << total_length << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
