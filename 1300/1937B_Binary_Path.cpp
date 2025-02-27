#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i,n) for(int i=0;i<n;i++)
#define fls(i,s,n) for(int i=s;i<n;i++)
#define flr(i,n) for(int i=n-1;i>=0;i--)
#define flrs(i,n,s) for(int i=n;i>=s;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
void asquare()
{
    ll n;
    cin>>n;
    string arr[2][n];
    for(int i=0;i<2;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            string x="";
            x+=s[j];
            arr[i][j]=x;
        }
    }
    string ans=arr[0][0];
    ll ways=1;
    ll i=0;
    ll j=0;
    ll x=1;
    while(j<n-1){
        if(i==0){
            if(arr[i][j+1]=="1"&&arr[i+1][j]=="0"){
                ans+=arr[i+1][j];
                i++;
                ways=x;
                x=1;
            }
            else if(arr[i][j+1]==arr[i+1][j]){
                ans+=arr[i][j+1];
                j++;
                x++;
            }
            else{
                ans+=arr[i][j+1];
                j++;
                x=1;
            }
        }
        else{
            ans+=arr[i][j+1];
            j++;
        }
    }
    if(i==0){
        ans+=arr[1][n-1];
        ways=x;
    }
    cout<<ans<<"\n";
    cout<<ways<<"\n";
}
//Main
int main()
{
     
    ll t;
    cin>>t;
    fl(i,t)
    {
        asquare();
    }
    return 0;
}
//End