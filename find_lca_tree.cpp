#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll parent[300000];						//stores parent of each node
ll level[300000];						//stores level of each node
ll FO[300000];							//first occurance of a node
ll VIS[300000];  						//visited ay for euler tour
ll ET[500000];							//euler tour 
ll idx;									//index for keeping count of elements in euler tour
vector<vector<ll>> adj(300000);
void euler_tour(ll u, ll depth)
{ 
    VIS[u] = 1;
    FO[u] = idx; 
    level[u] = depth;
    ET[idx++] = u;
    for (auto it : adj[u]) 
    { 
        if (!VIS[it]) 
        { 
            euler_tour(it,depth+1); 
            ET[idx++]=u;
        } 
    }
} 
ll min_value(ll i, ll j)
{
	if (i == -1) return j; 
    if (j == -1) return i; 
    return (level[ET[i]] <= level[ET[j]])? i : j; 
}
void build(ll seg_tree[], ll node, ll start, ll end)
{
    if(start == end)
        seg_tree[node] = start;
    else
    {
        ll mid = (start + end) / 2;
        build(seg_tree,2*node, start, mid);
        build(seg_tree,2*node+1, mid+1, end);
        seg_tree[node] = min_value(seg_tree[node*2],seg_tree[node*2+1]);
    }
}
ll query(ll seg_tree[], ll node,ll start,ll end,ll q_start,ll q_end)
{
    if(q_start>end||start>q_end)
        return -1;
    if(q_start<=start&&q_end>=end)
        return seg_tree[node];
    ll p1,p2;
    ll mid=(start+end)/2;
    p1=query(seg_tree,2*node,start,mid,q_start,q_end);
    p2=query(seg_tree,2*node+1,mid+1,end,q_start,q_end);
    return min_value(p1,p2);
}
ll find_lca(ll seg_tree[],ll u, ll v)
{
	ll start = FO[u];
	ll end = FO[v];
	if (start>end)
		swap(start,end);
	return query(seg_tree,1,0,idx-1,start,end);
}
int main()
{
	ll n, q, u, v;
	cin >> n >> q;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	idx = 0;
	euler_tour(0,0);
	ll x = (ll)(ceil(log2(idx)));
	ll max_size = 2*(ll)pow(2, x) - 1; 
	ll seg_tree[max_size+1];

	build(seg_tree,1,0,idx-1);					//parameters are seg_tree, start node, start index, end index	

	while(q--)									//now answer queries
	{
		cin >> u >> v;
		cout << ET[find_lca(seg_tree,u-1,v-1)] + 1 << '\n';
	}

	return 0;
}