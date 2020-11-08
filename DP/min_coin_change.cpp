#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	int coins[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> coins[i];
	}

	int dp[m+1][n+1];

	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if (j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (i==0)
			{
				dp[i][j] = INT_MAX-1;
				continue;
			}

			if (coins[i-1] <= j)
			{
				dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[m][n] << '\n';
	return 0;
}