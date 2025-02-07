#include <bits/stdc++.h>
using namespace std;

// #define int long long int
#define d1(x) cout << #x << ": " << x << endl
#define d2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define d3(x, y, z) cout << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define d4(a, b, c, d) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define d5(a, b, c, d, e) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define d6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl

#define pi pair<int, int>
#define vi vector<int>
#define dd double
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define ll long long int
#define pb push_back
// #define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define mp make_pair
#define in insert
#define fi first
#define lb lower_bound
#define ub upper_bound
#define se second
#define all(v) (v).begin(), (v).end()
const int MOD = 1e9 + 7;


void primeFactors(int n, unordered_map<int, int> &mp)
{
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n]++;
}

void allDivisor(int n){
    int count = 0;
    int sum = 0;
    for(int i=1; i*i <= n; i++){
        if(n%i==0){
            count++;
            sum+=i;
            if(n/i!=i){
                count++;
                sum+=n/i;
            }
        }
    }
    cout<<count<<" "<<sum<<endl;
}

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

//binary Exponential
int powB(int a, int b){
    if(b==0) return 1;
    int res = powB(a,b/2);
    if(b&1){
        return (a* (res *1LL* res)%MOD)%MOD;
    }
    return (res *1LL* res)%MOD;
}

//binary mul iterative
int binMul(int a, int b){
    int ans = 0;
    while(b){
        if(b&1){
            ans = (ans + a)%MOD;
        }
        a = (a + a)%MOD;
        b>>=1;
    }   
    return ans;
}


//iterative way
int powI(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = binMul(ans, a);
        }
        a = binMul(a,a);
        b = b>>1;
    }
    return ans;
}


//ETF count of number less than n, which are coprime
// phi(n) = n* π(1 + 1/p)
//where p is coprime numbers
// 5: 1, 2, 3, 4
// 6: 1, 5   because 2,3,4 has more than 1 prime similar
// (a^b)%M  =  a ^ (b % phi(M))%M;
//when we power it, b is moded with the etf of m and not just M
// if M is prime, (a^b)%M = a ^ (b% phi(M-1)) % M


// void solve() {
    
     
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin>>t;
//     while(t--)
//     solve();
    
//     return 0;
// }
struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* create(vi v){
    Node* head = new Node(v[0]);
    queue<Node*> q;
    q.push(head);
    int n=v.size();
    int i=1;
    while(i < n){
        Node* temp = q.front();
        q.pop();
        temp->left = new Node(v[i++]);
        q.push(temp->left);
        if(i<n){
            temp->right = new Node(v[i++]);
            q.push(temp->right);
        }
    }
    return head;
}

void inOrder(Node* head){
    if(!head) return;
     
    inOrder(head->left);
    cout<<head->data<<" ";
    inOrder(head->right);
    return;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(30,0));
    for(int i=0 ; i<n; i++){
        int x; cin>>x;
        int j=0;
        while(x){
            v[i][j]=x&1;
            x=x>>1;
            j++;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<30; j++){
            v[i][j] = v[i][j] + v[i-1][j];
        }
    }

    int q; cin>>q;
    while(q--){
        int l, k;
        cin>>l>>k;
        l--;
        int r=n-1;
        int ans=-2;
        int lo = l;
        while(lo<=r){
            int mid = lo + (r-lo)/2;
            int cal = 0;
            for(int i=0; i<30 ; i++){
                int c = l==0 ? v[mid][i] : v[mid][i] - v[l-1][i];
                if(c >= mid-l+1)
                {
                    cal = cal | (1<<i);
                }
            }
            if(cal>=k){
                ans = max(ans, mid);
                lo = mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans+1<<endl;
    }


    // for(int i=0 ; i<n; i++){
    //     for(int j=0 ; j<30; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}