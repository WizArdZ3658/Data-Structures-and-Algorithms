#include<bits/stdc++.h>
using namespace std;
int rod_cutting(int arr[], int n)
{
	int val[n+1];
	val[0] = 0;
	int i, j;

	for (int i = 1; i <= n; ++i)
	{
		int max_val = INT_MIN;
		for (int j = 0; j < i; ++j)
		{
			max_val = max(max_val, arr[j] + val[i-j-1]);
		}
		val[i] = max_val;
	}

	return val[n];
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << "Rod cutting : " << rod_cutting(arr, n) << '\n';
	return 0;
}