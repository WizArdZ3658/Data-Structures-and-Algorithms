// Given a set of integers, the task is to divide it into two 
// sets S1 and S2 such that the absolute difference between their sums is minimum.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum;

	int arr[n];
	int X = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		X += arr[i];
	}

	sum = X/2;

	bool dp[n+1][sum+1];

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			if (i==0)
			{
				dp[i][j] = false;
			}
			if (j==0)
			{
				dp[i][j] = true;
			}

			if (i!=0 && j!=0)
			{
				if (arr[i-1] <= j)
				{
					dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
					
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	for (int i = sum; i >= 0; --i)
	{
		if (dp[n][i])
		{
			cout << X - 2*i << '\n';
			return 0;
		}
	}
	return 0;
}