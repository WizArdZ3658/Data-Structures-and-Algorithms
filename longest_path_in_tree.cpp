#include <bits/stdc++.h>
using namespace std;
#define pb push_back
pair<int, int> bfs(vector<vector<int>> &adj, int u, int n)
{
	int dis[n];
	memset(dis, -1, sizeof(dis)); 
    queue<int> q; 
    q.push(u); 
    dis[u] = 0; 
    while (!q.empty()) 
    { 
        int t = q.front();
        q.pop(); 
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
            if (dis[v] == -1) 
            { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
    int maxDis = 0; 
    int nodeIdx; 
  
    //  get farthest node distance and its index 
    for (int i = 0; i < n; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis);
}
int main()
{
    /*You can also use 2 DFS runs to get the longest path in a tree*/
	int n, u, v;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	pair<int, int> t1, t2;
	t1 = bfs(adj,0,n);
	t2 = bfs(adj,t1.first,n);
	cout << t2.second;
	return 0;
}