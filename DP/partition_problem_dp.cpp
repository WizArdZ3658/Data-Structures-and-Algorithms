// Partition problem is to determine whether a given set can be partitioned into two subsets 
// such that the sum of elements in both subsets is the same. 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 0;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum&1)
	{
		cout << 0 << '\n';
		return 0;
	}

	sum = sum/2;

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

	cout << dp[n][sum] << '\n';
	return 0;
}