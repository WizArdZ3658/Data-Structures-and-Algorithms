#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
class myComparator 
{ 
	public: 
    int operator() (const pair<int, int> &p1, const pair<int, int> &p2) 
    { 
        return p1.first > p2.first; 
    } 
}; 
int main()
{
	int V, E;
	cout << "Enter number of vertices and edges : \n";
	cin >> V >> E;

	cout << "Enter edges with u, v and weight : \n";
	vector<vector<int>> adj(V);
	vector<vector<int>> weights(V, vector<int>(V));
	vector<int> marked(V, -1);

	int u, v, wt;

	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> wt;
		weights[u][v] = wt;
		weights[v][u] = wt;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, myComparator> pq;
	marked[0] = 1;
	for (int i = 0; i < adj[0].size(); ++i)
	{
		pq.push({weights[0][adj[0][i]], adj[0][i]});
	}

	int result = 0;
	int t = V-1;
	while(t)
	{
		pair<int, int> temp = pq.top();
		pq.pop();
		wt = temp.first;
		u = temp.second;

		if (marked[u]==1)
		{
			continue;
		}

		marked[u] = 1;
		result += wt;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			pq.push({weights[u][adj[u][i]], adj[u][i]});
		}
		t--;
	}

	cout << "result : " << result << '\n';
	return 0;
}