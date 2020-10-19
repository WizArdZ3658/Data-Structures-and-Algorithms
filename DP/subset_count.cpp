// Given an array arr[] of length N and an integer X, the task is 
// to find the number of subsets with sum equal to X.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum;
	cin >> sum;

	int arr[n];
	int X = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		X += arr[i];
	}

	if (sum > X)
	{
		cout << "not possible\n";
		return 0;
	}

	int dp[n+1][sum+1];

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			if (i==0)
			{
				dp[i][j] = 0;
			}
			if (j==0)
			{
				dp[i][j] = 1;
			}

			if (i!=0 && j!=0)
			{
				if (arr[i-1] <= j)
				{
					dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
					
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	cout << dp[n][sum] << '\n';
	return 0;
}