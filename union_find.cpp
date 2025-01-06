#include <bits/stdc++.h>
using namespace std;
int find_set(vector<int> &parent, int v) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent, parent[v]);
}
 
void union_sets(vector<int> &parent, vector<int> &siz, int a, int b) 
{
    a = find_set(parent, a);
    b = find_set(parent, b);
    
    if (a != b) 
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
int main()
{
	cout << "Enter the number of components :\n";
	
	int n;
	cin >> n;

	vector<int> parent(n+1);
	vector<int> siz(n+1);

	for (int i = 0; i < n+1; ++i)
	{
		parent[v] = v;
    	siz[v] = 1;
	}

	while(true)
	{
		cout << "Enter 1 to union_components, 2 to exit\n";
		int option;
		cin >> option;
		if (option==1)
		{
			cout << "Enter the two numbers you want to merge :\n";
			int a, b;
			cin >> a >> b;
			if (find_set(parent, a) != find_set(parent, b))
			{
				union_sets(parent, siz, a, b);
			}
		}
		else if (option==2)
		{
			break;
		}
		else
		{
			cout << "Wrong option\n";
		}
	}

	int result = 0;
	for (int i = 1; i < n+1; ++i)
	{
		if (parent[i]==i)
		{
			result++;
		}
	}

	cout << "No of isolated components : " << result << '\n';
	return 0;
}