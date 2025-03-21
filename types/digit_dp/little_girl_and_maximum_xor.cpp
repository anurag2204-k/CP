// D. Little Girl and Maximum XOR
// time limit per test: 1 second
// memory limit per test: 256 megabytes
// A little girt loves problems on bitwise operations very much. Here's one of them.
// You are given two integers I and r. Let's consider the values of a b for all pairs of integers a and b (I Sa b S r). Your task is to find
// the maximum value among all considered ones.
// Expression x y means applying bitwise excluding or operation to integers x and y. The given operation exists in all modern
// , in Pascal — as "xor"
// programming languages, for example, in languages C++ and Java it is represented as
// Input
// The single line contains space-separated integers I and r (1 S I S r 1018).
// Please, do not use the Slid specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the 8164d
// specifier.
// Output
// In a single line print a single integer — the maximum value ofa b for all pairs of integers a, b (l Sa b S r).
// Examples
// input
// output
// 3
// input
// 8 16
// output
// 31

// Editorial -------------------------------------------------------------------------------------------

// First of all we should convert L and R to the binary numeral system. Now we can solve our problem with dynamic programming, using the following state d[p][l1][l2][r1][r2], where p is current position in binary representation of our numbers a and b (this parameter is in range from 0 to number of bits in R), l1(0 or 1) is a variable, which shows if current value of а is strictly greater than L, l2(от 0 до1) is a variable, which shows if current value of а is strictly less then R, r1,r2are variables, which show the similar things for b.
// Let’s use recursion with memorization for our solution.
// Let’s define the base of recursion. If we have looked through all the bits, we should return 0.
// Let’s define a recursive transition. We need to know, which bits we can place into binary representation of number а in p-th position. We can place 0 if the following condition is true: p-th bit of L is equal to 0, or p-th bit of L is equal to 1 and variable fl1 shows that current value of a is strictly greater then L. Similarly, we can place 1 if the following condition is true: p-th bit of R is equal to 1, or p-th bit of R is equal to 0 and variable fr1 shows that current value of a is strictly less then R. Similarly, we can obtain, which bits we can place into binary representation of number b in p-th position.
// Let’s iterate through all possible bits’ values and check the result of xor operation. If it is equal to 1, we should add to the answer corresponding power of 2. We also need carefully recalculate values of variables fl1, fr1, fl2, fr2. We should choose maximum answer from all valid options.
// Initial state for our recursion is (P,0,0,0,0), where P is number of bits in R.
// I hope, my code will clarify all the obscure points.
// I also want to say, that this approach is in some sense universal and can be applied to many similar problems
// The complexity of algorithm is O(logR)

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
string s1, s2;
lli dp[101][2][2][2][2];
int n;

// l1=tight_low1 for first num
// l2=tight_up1 for first num
// r1=tight_low2 for second num
// r2= tight_up2 for second num
lli solve(int pos, int l1, int l2, int r1, int r2)
{
    if (pos == n)
    {
        return 0;
    }
    else if (dp[pos][l1][l2][r1][r2] != -1)
    {
        return dp[pos][l1][l2][r1][r2];
    }
    else
    {
        lli ret = 0;
        int minl = 0, maxl = 1, minr = 0, maxr = 1;
        // range  values that can be set
        // for both nums at ith position
        if (l1 == 1 && s1[pos] == '1')
        {
            minl = 1;
        }
        if (l2 == 1 && s2[pos] == '0')
        {
            maxl = 0;
        }

        if (r1 == 1 && s1[pos] == '1')
        {
            minr = 1;
        }

        if (r2 == 1 && s2[pos] == '0')
        {
            maxr = 0;
        }
        for (int i = minl; i <= maxl; i++)
        {
            for (int j = minr; j <= maxr; j++)
            {

                int nl1 = l1, nl2 = l2, nr1 = r1, nr2 = r2;

                if (s1[pos] < (i + '0'))
                {
                    nl1 = 0;
                }
                if (s2[pos] > (i + '0'))
                {
                    nl2 = 0;
                }

                if (s1[pos] < (j + '0'))
                {
                    nr1 = 0;
                }
                if (s2[pos] > (j + '0'))
                {
                    nr2 = 0;
                }

                int xr = (i ^ j);
                lli sum = 0;
                if (xr == 1)
                {
                    int size = n - pos - 1;
                    sum = (1ll << size);
                }
                lli ret1 = (solve(pos + 1, nl1, nl2, nr1, nr2) + sum);

                ret = max(ret, ret1);
            }
        }
        dp[pos][l1][l2][r1][r2] = ret;
        return ret;
    }
}

string bin(lli num)
{
    string temp;
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            temp += '0';
        }
        else
            temp += '1';
        num /= 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    lli a, b;
    cin >> a >> b;
    s1 = bin(a);
    s2 = bin(b);
    n = s2.length();
    if (s1.length() < s2.length())
    {
        string temp;
        int dif = s2.length() - s1.length();
        for (int i = 0; i < dif; i++)
            temp += '0';
        temp += s1;
        s1 = temp;
    }
    memset(dp, -1, sizeof dp);
    lli ans = solve(0, 1, 1, 1, 1);
    cout << ans << endl;
}
