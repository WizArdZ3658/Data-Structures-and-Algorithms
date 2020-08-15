#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class comp
{
	public:
	bool operator() (pair<int, int> &p1, pair<int, int> &p2)
	{
		return p1.first>p2.first;
	}	
};
int main()
{
	int V, E;
	cout << "Enter number of vertices and edges\n";
	cin >> V >> E;

	vector<vector<int>> weights(V, vector<int>(V, INT_MAX));
	vector<vector<int>> adj(V);

	cout << "Enter u, v and wt\n";
	int u, v, wt;
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> wt;
		adj[u].push_back(v);
		adj[v].push_back(u);
		weights[u][v] = wt;
		weights[v][u] = wt;
	}

	cout << "enter source and destination\n";
	int source, destination;
	cin >> source >> destination;

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	vector<int> distance(V, INT_MAX);
	vector<int> calculated(V, -1);
	calculated[source] = 1;
	distance[source] = 0;

	for (int i = 0; i < adj[source].size(); ++i)
	{
		pq.push({weights[adj[source][i]][source], adj[source][i]});
		distance[adj[source][i]] = weights[adj[source][i]][source];
	}


	while(!pq.empty())
	{
		pair<int, int> temp = pq.top();
		pq.pop();

		int u = temp.second;
		if (calculated[u] == 1)
		{
			continue;
		}
		calculated[u] = 1;

		for (int i = 0; i < adj[u].size(); ++i)
		{
			if (calculated[adj[u][i]]==-1)
			{
				distance[adj[u][i]] = min(distance[adj[u][i]], distance[u]+weights[u][adj[u][i]]);
				pq.push({distance[adj[u][i]], adj[u][i]});
			}
			
		}
	}

	cout << "The shortest distance is : " << distance[destination] << '\n';
	return 0;
}