#include <bits/stdc++.h>
using namespace std;
int timestamp, idx;
void euler_tour(int u, int parent, vector<vector<int>> &adj, int start_idx[], int end_idx[], int euler_t[])
{ 
    start_idx[u] = timestamp;
    timestamp++;
    euler_t[idx++] = u;
    for (auto it : adj[u]) 
    { 
        if (it != parent) 
        { 
            euler_tour(it, u, adj, start_idx, end_idx, euler_t); 
        } 
    }
    end_idx[u] = timestamp-1;
} 
int main()
{
	/*This code flattens (or converts) the tree into linear array which can be later used
	to run range queries to get faster results
	start_idx[i] stores the start index of the subarray of node i
	end_idx[i] stores the end index of the subarray of node i
	euler_t[] stores the values of nodes in ascending order of discovery times*/
	int n, u, v;
	timestamp = 0;
	idx = 0;
	cin >> n;
	vector<vector<int>> adj(n);
	int euler_t[n];
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	int start_idx[n], end_idx[n];
	euler_tour(0, -1, adj, start_idx, end_idx, euler_t);

	cout << '\n';
	cout << "Euler Tour order : " ;
	for (int i = 0; i < n; ++i)
	{
		cout << euler_t[i] << " ";
	}
	cout << "\n\n";
	cout << "Start Index :\t" ;
	for (int i = 0; i < n; ++i)
	{
		cout << start_idx[i] << " ";
	}
	cout << '\n';
	cout << "End Index :\t" ;
	for (int i = 0; i < n; ++i)
	{
		cout << end_idx[i] << " ";
	}
	cout << '\n';

	return 0;
}