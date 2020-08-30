#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int result[n] = {0};
	result[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				result[i] = max(result[i], result[j]+1);
			}
			
		}
	}

	cout << *max_element(result, result+n);
	return 0;
}