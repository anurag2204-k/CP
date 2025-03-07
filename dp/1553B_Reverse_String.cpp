// 1553B	Reverse String
#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;
 
using namespace std;






//first way -------------------------------------------------------------------------------------------

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    bool found = false;
    for(int i = 0; i<n; i++){
        if(found) break;
        if(s[i]==t[0]){
            int covered = 0;
            for(int j = i; j < n; j++){
                if(s[j] == t[covered]){
                    covered++;
                    if(covered == m){
                        found = true;
                        break;
                    }
                    int left = m-covered;
                    int here = j;
                    if(here >= left){
                        string rev = s.substr(j-left, left);
                        reverse(rev.begin(), rev.end());
                        if(rev == t.substr(covered, left)){
                            found = true;
                            break;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    if(found){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
// second way -------------------------------------------------------------------------------------------
 
int left(string s, string t, int i, int x)
{
    while (x < t.length() && i >= 0)
    {
        if (t[x] == s[i])
        {
            x++;
            i--;
        }
        else
        {
            break;
        }
    }
    if (x == t.length())
    {
        return 1;
    }
    return 0;
}
 
int right(string s, string t, int i, int x)
{
    if (x == t.length())
    {
        return 1;
    }
    if (x + 1 == t.length())
    {
        if (i + 1 < s.length() && s[i + 1] == t[x])
        {
            return 1;
        }
        else if (i - 1 >= 0 && s[i - 1] == t[x])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 
    int r1 = 0, r2 = 0;
    if (i - 1 >= 0 && s[i - 1] == t[x])
    {
        r1 = left(s, t, i - 1, x);
    }
    if (r1)
    {
        return 1;
    }
    if (i + 1 < s.length() && s[i + 1] == t[x])
    {
        r2 = right(s, t, i + 1, x + 1);
    }
 
    return (r1 || r2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int ttt;
    cin >> ttt;
    for (int tt = 0; tt < ttt; tt++)
    {
        string s, t;
        cin >> s >> t;
 
        int f = 0;
        int l = t.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[0])
            {
                f = right(s, t, i, 1);
                if (f == 1)
                {
                    break;
                }
            }
        }
        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
 
    return 0;
}