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


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int open=0, close=0;    
    for(int i=0;i<n; i++){
        if(s[i]=='(')open++;
        else close++;
    }
    if(open!=close){
        cout<<-1<<endl;
        return;
    }

    vector<int>ans(n,0);
    int cur = s[0] == '(' ? 1:2;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(cnt == 0){
           cur = s[i] == '(' ? 1:2; 
        }
        if(s[i]=='(') cnt++;
        else{
            cnt--;
        }
        ans[i]=cur;
    }

    int type = 1;
    for(int i=0; i<n-1; i++){
        if(ans[i]!=ans[i+1]) {
            type++; break;
        }
    }
    if(type==1){
        cout<<1<<endl;
        for(int i=0; i<n; i++){
        cout<<1<<" ";
        }
    }else{
        cout<<2<<endl;
        for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    solve();
    
    return 0;
}
