#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout << "Enter length of the rod\n";
	int n;
	cin >> n;

	int price[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	int dp[n+1][n+1];

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if (i==0 || j==0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (i <= j)
			{
				dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << "Max profit : " << dp[n][n] << '\n';

	return 0;
}