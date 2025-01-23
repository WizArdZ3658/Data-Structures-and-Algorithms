#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void merge_sort(vector<int> &arr, int start, int end)
{
	if (start<end)
	{
		int mid = (start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);

		vector<int> temp;
		int p1 = start, p2 = mid+1;
		while(p1<=mid && p2<=end)
		{
			if (arr[p1]<arr[p2])
			{
				temp.push_back(arr[p1]);
				p1++;
			}
			else
			{
				temp.push_back(arr[p2]);
				p2++;
			}
		}

		if (p1==mid+1)
		{
			while(p2<=end)
			{
				temp.push_back(arr[p2]);
				p2++;
			}
		}
		else if (p2==end+1)
		{
			while(p1<=mid)
			{
				temp.push_back(arr[p1]);
				p1++;
			}
		}


		int k = 0;
		for (int i = start; i <= end; ++i)
		{
			arr[i] = temp[k++];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	merge_sort(arr, 0, n-1);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
	return 0;
}