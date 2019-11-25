/*
go to https://www.geeksforgeeks.org/compute-ncr-p-set-1-introduction-and-dynamic-programming-solution/
to understand how this dynamic prog solution works.
*/
#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll unsigned long long
const int mod = 13;				//adjust mod value according to your need
void init_fact(ll arr[])
{
	arr[0] = 1;
	for (int i = 1; i <= 1e9; ++i)
		arr[i] = (arr[i-1]*i)%mod;
}
int nCrmod_dynamic(int n, int r)
{
	int dp[r+1] = {0};		
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = min(i,r); j > 0; j--)
		{
			dp[j] = (dp[j] + dp[j-1])%mod;
		}
	}

	return dp[r];
}
int main()
{
	int n, r;
	//ll factorial[1e9+1];
	//init_fact(factorial);
	cin >> n >> r;
	cout << nCrmod_dynamic(n,r);
	return 0;
}