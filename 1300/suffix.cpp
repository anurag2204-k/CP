#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    unordered_map<int, int> pos_in_a;
    
    // Read list a and store positions
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos_in_a[a[i]] = i;
    }
    
    // Read list b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Start from the end of b and find the longest suffix
    // that maintains relative order as in a
    int i = n - 1;
    int min_pos = n;
    
    while (i >= 0) {
        if (pos_in_a[b[i]] < min_pos) {
            min_pos = pos_in_a[b[i]];
            i--;
        } else {
            break;
        }
    }
    
    // The members from 0 to i must have been online
    return i + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cout << solve() << endl;
    }
    
    return 0;
}