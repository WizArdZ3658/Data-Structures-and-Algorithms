#include<iostream>
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

	int max_so_far = arr[0];
	int max_ending_so_far = arr[0];

	for (int i = 1; i < n; ++i)
	{
		max_ending_so_far = max(arr[i], max_ending_so_far + arr[i]);
		max_so_far = max(max_so_far, max_ending_so_far);

	}

	cout << max_so_far;
	return 0;
}