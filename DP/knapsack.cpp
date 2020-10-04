#include<iostream>
using namespace std;
int main()
{
	cout << "Enter number of items : \n";
	int n;
	cin >> n;

	int value[n], weight[n];
	cout << "Enter value and weight of each item : \n";
	for (int i = 0; i < n; ++i)
	{
		cin >> value[i] >> weight[i];
	}

	cout << "Enter limit \n";
	int W;
	cin >> W;

	int DP[n+1][W+1];

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			if(i==0 || j==0)
			{
				DP[i][j] = 0;
			}
			else if(weight[i-1] <= j)
			{
				DP[i][j] = max(DP[i-1][j], DP[i-1][j-weight[i-1]] + value[i-1]);
			}
			else
			{
				DP[i][j] = DP[i-1][j];
			}
		}
	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= W; ++j)
	// 	{
	// 		cout << DP[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }

	cout << "Result : " << DP[n][W] << '\n';
	return 0;
}