#include <bits/stdc++.h>
using namespace std;
int solution(string s)
{
	int n = s.size();
	bool palindrome[n][n];
	memset(palindrome, false, sizeof(palindrome));
	int cuts[n];

	for (int i = 0; i < n; ++i)
	{
		palindrome[i][i] = true;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < n - i + 1; ++j)
		{
			int k = j + i - 1;

			if (i==2)
			{
				palindrome[j][k] = (s[j]==s[k]);
			}
			else
			{
				palindrome[j][k] = (s[j]==s[k] && palindrome[j+1][k-1]);
			}
		}
	}


	for (int i = 0; i < n; ++i)
	{
		if (palindrome[0][i]==true)
		{
			cuts[i] = 0;
		}
		else
		{
			cuts[i] = INT_MAX;
			for (int j = 0; j < i; ++j)
			{
				if (palindrome[j+1][i] == true && 1 + cuts[j] < cuts[i])
				{
					cuts[i] = 1 + cuts[j];
				}
			}
		}
	}

	return cuts[n-1];
}
int main()
{
	string s;
	cin >> s;
	cout << solution(s) << '\n';
	return 0;
}