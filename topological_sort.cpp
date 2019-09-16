#include <bits/stdc++.h>
using namespace std;
void topological_order(vector<vector<int>> &adj)
{
	/*
	step 1 -> intialise indegrees to zero
	step 2 -> set the indegrees of each vertex from adj lists
	step 3 -> push the vertices with indeg 0 into the queue
	step 4 -> 1)pop and print and reduce the indeg of vertices present 
			int its adj list
			2)if indeg becomes zero push it into the queue
	step 5 -> repeat step 4 until the queue becoems empty

	*/
	int n = adj.size();
	int indegree[n] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		{
			indegree[adj[i][j]]++;
		}
	}
	/*
	cout << "Indegrees : \n";			//prints out indegress of vertices
	for (int i = 0; i < n; ++i)
	{
		cout << indegree[i] << " ";
	}
	cout << '\n';*/
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
		cout << u+1 << " ";
		for (int i = 0; i < adj[u].size(); ++i)
		{
			indegree[adj[u][i]]--;
			if (indegree[adj[u][i]] == 0)
			{
				q.push(adj[u][i]);
			}

		}
	}

}
int main()
{
	/*
	There is another way of finding topological ordering of a graph :-
	1> run DFS to find the finishing times of each node
	2> print the nodes in decresing order of their finishing times
	You'll get your topological ordering :)
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
	topological_order(adj);
	return 0;
}