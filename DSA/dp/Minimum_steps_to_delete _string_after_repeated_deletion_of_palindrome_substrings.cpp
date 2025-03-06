// C++ program to find minimum step to delete a string

// {`https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/`}

#include <bits/stdc++.h>
using namespace std;

/* method returns minimum step for deleting the string,
where in one step a palindrome is removed */
int helper(string str, int si, int ei,
		vector<vector<int> >& dp)
{

	// if the string is empty
	// need no operation
	if (si > ei)
		return 0;

	// string length one
	// need one operation
	if (ei - si + 1 == 1)
		return 1;

	// if already calculated
	if (dp[si][ei] != -1)
		return dp[si][ei];

	// to consider three options
	int op1 = 1e9, op2 = 1e9, op3 = 1e9;

	// delete first char and call
	// on the smaller subproblem
	op1 = 1 + helper(str, si + 1, ei, dp);

	// first two characters are same
	if (str[si] == str[si + 1])
		op2 = 1 + helper(str, si + 2, ei, dp);

	// found another index where the
	// character is same as si-th character
	for (int i = si + 2; i <= ei; i++) {
		if (str[si] == str[i])
			op3 = min(op3,
					helper(str, si + 1, i - 1, dp)
						+ helper(str, i + 1, ei, dp));
	}

	// return the minimum b/w three options
	return dp[si][ei] = min({ op1, op2, op3 });
}

int minStepToDeleteString(string s)
{
	int n = s.size();

	// dp table to remove repeatations
	vector<vector<int> > dp(n, vector<int>(n, -1));

	// passing starting and ending index
	return helper(s, 0, n - 1, dp);
}

// Driver Code
int main()
{
	string str = "2553432";
	cout << minStepToDeleteString(str) << endl;
	return 0;
}




//  2. Minimum steps to delete a string after repeated deletion of palindrome substrings --------------------------------------------------------------------------------------------------------------------------------
// C++ program to find minimum step to delete a string
#include <bits/stdc++.h>
using namespace std;

/* method returns minimum step for deleting the string,
where in one step a palindrome is removed */
int minStepToDeleteString(string str)
{
	int N = str.length();

	// declare dp array and initialize it with 0s
	int dp[N + 1][N + 1];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			dp[i][j] = 0;

	// loop for substring length we are considering
	for (int len = 1; len <= N; len++)
	{
		// loop with two variables i and j, denoting
		// starting and ending of substrings
		for (int i = 0, j = len - 1; j < N; i++, j++)
		{
			// If substring length is 1, then 1 step
			// will be needed
			if (len == 1)
				dp[i][j] = 1;
			else
			{
				// delete the ith char individually
				// and assign result for subproblem (i+1,j)
				dp[i][j] = 1 + dp[i + 1][j];

				// if current and next char are same,
				// choose min from current and subproblem
				// (i+2,j)
				if (str[i] == str[i + 1])
					dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);

				/* loop over all right characters and suppose
					Kth char is same as ith character then
					choose minimum from current and two
					substring after ignoring ith and Kth char */
				for (int K = i + 2; K <= j; K++)
					if (str[i] == str[K])
						dp[i][j] = min(dp[i+1][K-1] + dp[K+1][j],
													dp[i][j]);
			}
		}
	}

	/* Uncomment below snippet to print actual dp tablex
	for (int i = 0; i < N; i++, cout << endl)
		for (int j = 0; j < N; j++)
			cout << dp[i][j] << " "; */

	return dp[0][N - 1];
}

// Driver code to test above methods
int main()
{
	string str = "2553432";
	cout << minStepToDeleteString(str) << endl;
	return 0;
}









