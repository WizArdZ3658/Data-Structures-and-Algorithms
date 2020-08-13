#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
	int u;
	int v;
	int wt;
};
bool custom(edge &a, edge &b)
{
	return a.wt <= b.wt;
}
int find(int a, vector<int> &nodes)
{
	while(a!=nodes[a])
	{
		a = nodes[a];
	}

	return a;
}
void nodes_union(int a, int b, vector<int> &nodes)
{
	int x = find(a, nodes);
	int y = find(b, nodes);

	nodes[a] = min(x, y);
	nodes[b] = min(x, y);
}
int main()
{
	int V, E;
	cout << "Enter number of vertices and edges : \n";
	cin >> V >> E;

	cout << "Enter edges with u, v and weight : \n";
	vector<edge> arr(E);
	for (int i = 0; i < E; ++i)
	{
		cin >> arr[i].wt >> arr[i].u >> arr[i].v;
	}
	sort(arr.begin(), arr.end(), custom);

	vector<int> nodes(V);
	for (int i = 0; i < V; ++i)
	{
		nodes[i] = i;
	}

	int result = 0;
	int edge_count = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (find(arr[i].u, nodes) == find(arr[i].v, nodes))
		{
			continue;
		}
		else
		{
			result += arr[i].wt;
			nodes_union(arr[i].u, arr[i].v, nodes);
			edge_count++;
		}

		if (edge_count == V-1)
		{
			break;
		}
	}

	cout << result << '\n';
	return 0;
}