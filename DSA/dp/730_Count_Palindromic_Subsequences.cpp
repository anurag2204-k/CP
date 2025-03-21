class Solution{
    public:
    const long long int mod = 1000000007;
    long long int add(long long int x, long long int y) {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int func(int i, int j, string &str){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        else if(str[i]==str[j]){
            return add(add(func(i+1, j, str), func(i, j-1, str)), 1);
        }
        else
            return add(func(i+1, j, str), sub(func(i, j-1, str), func(i+1, j-1, str)));
    }
    long long int  countPS(string str){
       int n=str.size();
       return func(0, n-1, str);
    }
};