#include <bits/stdc++.h>
using namespace std;
void build(int seg_tree[], int arr[], int node, int start, int end)
{
	if (start==end)
	{
		seg_tree[node] = arr[start];
	}
	else
	{
		int mid = (start+end)/2;
		build(seg_tree, arr, 2*node, start, mid);
		build(seg_tree, arr, 2*node+1, mid+1, end);
		seg_tree[node] = seg_tree[node*2] + seg_tree[node*2+1];
	}
}
int query(int seg_tree[], int l_bound, int r_bound, int node, int l_query, int r_query)
{
	if (l_query>r_bound || r_query<l_bound)
	{
		return 0;
	}
	if (l_query<=l_bound && r_query>=r_bound)
	{
		return seg_tree[node];
	}
	int mid = (l_bound+r_bound)/2;
	int lsum = query(seg_tree, l_bound, mid, 2*node, l_query, r_query);
	int rsum = query(seg_tree, mid+1, r_bound, 2*node+1, l_query, r_query);
	return lsum+rsum;
}
int main()
{
	int n, q, l, r;
	cin >> n >> q;
	int arr[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height) - 1; 
    int seg_tree[max_size+1] = {0};
    build(seg_tree, arr, 1, 1, n);
    cout << "Queries start here\n";
    while(q--)
    {
    	cin >> l >> r;
    	cout << query(seg_tree,1,n,1,l,r) << '\n';
    }
    /*for (int i = 0; i <= max_size; ++i)
	{
		cout << seg_tree[i] << " ";
	}*/
	return 0;
}