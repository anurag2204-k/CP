#include <bits/stdc++.h>
using namespace std;



void read() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void faster() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


vector<long long> adj[200003];
vector<long long> num(200003, 0);
vector<long long> dp(200003, 0);
vector<long long> ans(200003, 0);

void dfs1(long long node, long long par){
    num[node] = 1;
    dp[node] = 0;
    for(auto child : adj[node]){
        if(child == par) continue;
        dfs1(child, node);
        num[node] += num[child];
        dp[node] += dp[child] + num[child];
    }
}

void dfs(long long node, long long par){
    ans[node] = dp[node];
    for(auto child : adj[node]){
        if(child == par) continue;
        long long dpn = dp[node], numn = num[node];
        long long dpc = dp[child], numc = num[child];

        dp[node] -= dp[child] + num[child];
        num[node] -= num[child];
        dp[child] += dp[node] + num[node];
        num[child] += num[node];

        dfs(child, node);

        dp[node] = dpn;
        num[node] = numn;
        dp[child] = dpc;
        num[child] = numc;
    }
}

void better(long long node, long long par, long long par_ans, long long total){
    ans[node] = dp[node] + par_ans + total - num[node];
    for(auto child : adj[node]){
        if(child == par) continue;
        better(child, node, ans[node] - (dp[child] + num[child]), total);
    }
    
}

int main(){
    faster();

    #ifndef ONLINE_JUDGE
    read();
    #endif
    long long n; cin>>n;
    for(long long i = 0; i< n-1; i++){
        long long a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);
    // dfs(1, 0);
    better(1, 0, 0, n);

    for(long long i = 1; i<= n; i++){
        cout<<ans[i]<<" ";
    }
    #ifndef ONLINE_JUDGE
    // test_main();
    // cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
