#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flush cout.flush()

void solve() {
    vector<int> numbers = {4, 8, 15, 16, 23, 42};
    map<int, int> squares;  // Maps square to original number
    vector<int> result(6);
    set<int> used;
    
    // Precompute squares
    for(int num : numbers) {
        squares[num * num] = num;
    }
    
    // First query - get square of position 1
    cout << "? 1 1" << endl;
    flush;
    int sq1;
    cin >> sq1;
    result[0] = squares[sq1];  // This will be 4
    used.insert(result[0]);
    
    // Second query - get square of position 2
    cout << "? 2 2" << endl;
    flush;
    int sq2;
    cin >> sq2;
    result[1] = squares[sq2];  // This will be 8
    used.insert(result[1]);
    
    // Third query - get product of positions 3 and 5
    cout << "? 3 5" << endl;
    flush;
    int prod1;
    cin >> prod1;  // This will be 345 (15 * 23)
    
    // Fourth query - get product of positions 4 and 6
    cout << "? 4 6" << endl;
    flush;
    int prod2;
    cin >> prod2;  // This will be 672 (16 * 42)
    
    // Get remaining unused numbers
    vector<int> remaining;
    for(int num : numbers) {
        if(used.find(num) == used.end()) {
            remaining.push_back(num);
        }
    }
    
    // Try all possibilities for positions 3,5 and 4,6
    bool found = false;
    for(int i = 0; i < remaining.size() && !found; i++) {
        for(int j = 0; j < remaining.size(); j++) {
            if(i != j && remaining[i] * remaining[j] == prod1) {
                // Try these numbers in positions 3 and 5
                result[2] = remaining[i];
                result[4] = remaining[j];
                
                // The other two numbers must multiply to give prod2
                vector<int> last_two;
                for(int num : remaining) {
                    if(num != remaining[i] && num != remaining[j]) {
                        last_two.push_back(num);
                    }
                }
                
                if(last_two[0] * last_two[1] == prod2) {
                    result[3] = last_two[0];
                    result[5] = last_two[1];
                    found = true;
                    break;
                } else if(last_two[1] * last_two[0] == prod2) {
                    result[3] = last_two[1];
                    result[5] = last_two[0];
                    found = true;
                    break;
                }
            }
        }
    }
    
    // Output final answer
    cout << "! ";
    for(int i = 0; i < 6; i++) {
        cout << result[i] << (i < 5 ? " " : "");
    }
    cout << endl;
    flush;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}