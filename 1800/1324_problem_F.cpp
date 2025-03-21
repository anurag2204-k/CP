#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
vector<int> tree[50001];
int dp1[50001][501], dp2[50001][501];
 
void dfs(int src, int par, int& k)
{
    for(int child : tree[src])
        if(child != par)
            dfs(child, src, k);
 
    dp1[src][0] = 1;
    for(int distance = 1; distance <= k; distance++)
    {
        dp1[src][distance] = 0;
        for(int child : tree[src])
            if(child != par)
                dp1[src][distance] += dp1[child][distance-1];
    }
}
 
void solve(int src, int par, int& k)
{
    for(int dis = 0; dis <= k; dis++)
        dp2[src][dis] = dp1[src][dis];
 
    if(par != 0)
    {
       dp2[src][1] += dp2[par][0];
       for(int dis = 2; dis <= k; dis++)
       {
           dp2[src][dis] += dp2[par][dis - 1];
           dp2[src][dis] -= dp1[src][dis - 2];
       }
    }
 
    for(int child : tree[src])
        if(child != par)
            solve(child, src, k);
}
 
int main() {
   fast_io;
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n >> k;
        fr(0,n-1)
        {
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
 
        dfs(1,0,k);
        solve(1,0,k);
 
        ll ans = 0;
        fr(1,n+1)
            ans += dp2[i][k];
        cout << (ans/2) ;
   }
   return 0;
}