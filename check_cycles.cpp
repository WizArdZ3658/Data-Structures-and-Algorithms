#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj, int visited[], int u)
{
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if (visited[adj[u][i]] == 0)
		{
			if (dfs(adj,visited,i))
				return true;
		}
		else
		{
			return true;
		}
	}
	return false;
}
bool isCyclic(vector<vector<int>> &adj, int visited[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (visited[i]==0)
		{
			if (dfs(adj,visited,i))
				return true;
		}
	}
	return false;
}
int main()
{
	cout << "Enter number of vertices\n";
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	cout << "Enter number of edges\n";
	int e, u, v;
	cin >> e;
	cout << "Enter the u-v pairs where edge goes from u to v\n";
	while(e--)
	{
		cin >> u >> v;
		adj[u-1].push_back(v-1);
	}
	int visited[n] = {0};
	if (isCyclic(adj,visited,n))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}