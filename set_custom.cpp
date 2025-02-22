#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

class myComparator
{
	public:
	int operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};
int main()
{
	set<pair<int, int>, myComparator> segs;
	cout << "Enter number of values :- ";

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		segs.insert(make_pair(t1, t2));
	}

	cout << "\nSpitting out values : \n";
	while(!segs.empty())
	{
		pair<int, int> temp = *segs.begin();
		segs.erase(segs.begin());
		cout << temp.first << " " << temp.second << '\n';
	}
	return 0;
}