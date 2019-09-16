#include <bits/stdc++.h>
using namespace std;
int longest_path(vector<vector<int>> &adj)
{
	int n = adj.size();
	int indegree[n] = {0};
	int l_path[n] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		{
			indegree[adj[i][j]]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u  = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i)
		{
			indegree[adj[u][i]]--;
			l_path[adj[u][i]] = max(l_path[adj[u][i]],l_path[u]+1);
			if (indegree[adj[u][i]] == 0)
			{
				q.push(adj[u][i]);
			}

		}
	}
	int answer = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		answer = max(answer, l_path[i]);
	}
	return answer;
}
int main()
{
	/*
	the code will be similar to topological sort
	*/
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
	cout << "Answer : " << longest_path(adj) + 1 << '\n';
	return 0;
}