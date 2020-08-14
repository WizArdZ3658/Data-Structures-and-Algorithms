#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
using namespace std;
#define INF 99999 
int main()
{
	int u, v, wt, V, E;
	cout << "Enter number of vertices and edges\n";
	cin >> V >> E;

	vector<vector<int>> graph(V, vector<int>(V, INF));
	for (int i = 0; i < V; ++i)
	{
		graph[i][i] = 0;
	}

	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> wt;
		graph[u][v] = wt;
		graph[v][u] = wt;
	}

	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			for (int k = 0; k < V; ++k)
			{
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}

	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}