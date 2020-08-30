#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) 
{
    int n = nums.size();
    int r = nums[0];
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        if (nums[i] < 0)
            swap(imax, imin);
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);
        r = max(r, imax);
    }
    return r;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << maxProduct(arr);
	return 0;
}