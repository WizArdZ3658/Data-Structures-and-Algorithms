#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *start, *current;
	cout << "Enter length\n";
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		struct node *temp2 = (struct node *)malloc(sizeof(struct node));
		temp2->data = temp;
		if (i==0)
		{
			start = temp2;
			current = start;
		}
		else if (i != n-1)
		{
			current->next = temp2;
			current = current->next;
		}
		else
		{
			current->next = temp2;
			temp2->next = NULL;
		}
	}

	current = start;

	while(current->next != NULL)
	{
		cout << current->data << '\n';
		current = current->next;
	}
	cout << current->data << '\n';
	return 0;
}