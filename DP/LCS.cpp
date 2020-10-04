#include<iostream>
using namespace std;
int longest_common_subsequence(string s, string t)
{
	int n = s.size();
	int m = t.size();

	int arr[n+1][m+1];

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			if(i==0 || j==0)
			{
				arr[i][j] = 0;
			}
			else if(s[i-1]==t[j-1])
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}

	return arr[n][m];
}
int longest_common_subarray(string s, string t)
{
	int n = s.size();
	int m = t.size();

	int arr[n+1][m+1];
	int result = 0;

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			if(i==0 || j==0)
			{
				arr[i][j] = 0;
			}
			else if(s[i-1]==t[j-1])
			{
				arr[i][j] = arr[i-1][j-1] + 1;
				result = max(result, arr[i][j]);
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}

	return result;
}
int main(int argc, char const *argv[])
{
	cout << "Enter strings : \n";
	string s, t;
	cin >> s >> t;
	cout << "longest common subsequence : " << longest_common_subsequence(s, t) << '\n';
	cout << "longest common subarray : " << longest_common_subarray(s, t) << '\n';
	return 0;
}