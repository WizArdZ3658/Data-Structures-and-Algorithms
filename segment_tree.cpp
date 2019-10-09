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
void update(int seg_tree[], int node, int idx, int val, int start, int end)
{
	if(start == end)
    {
        seg_tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(seg_tree, 2*node, idx, val, start, mid);
        }
        else
        {
            update(seg_tree, 2*node+1, idx, val, mid+1, end);
        }
        seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
    }
}
int main()
{
	int n, l, r, x;
	cin >> n;
	int arr[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height) - 1; 
    int seg_tree[max_size+1] = {0};
    build(seg_tree, arr, 1, 1, n);
    cout << "Queries start here 1 for query, 2 for update, 3 for exit\n";
    while(true)				//answer queries of update and finding sum
    {
    	cin >> x;
    	if(x==1)
    	{
    		cin >> l >> r;
    		cout << query(seg_tree,1,n,1,l,r) << '\n';
    	}
    	else if(x==2)
    	{
    		cin >> l >> r;
    		int diff = r - arr[l];
    		arr[l] = r;
    		update(seg_tree,1,l,diff,1,n);
    	}
    	else if (x==3)
    	{
    		break;
    	}
    	else
    	{
    		cout << "enter valid option\n" ;
    	}
    }
    /*for (int i = 0; i <= max_size; ++i)
	{
		cout << seg_tree[i] << " ";
	}*/
	return 0;
}