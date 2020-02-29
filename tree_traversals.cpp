#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void add_to_tree(struct node *root, int dat)
{
	if (dat > root->data)
	{
		if (root->right == NULL)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			root->right = temp;
			temp->left = NULL;
			temp->right = NULL;
			temp->data = dat;
		}
		else
		{
			root = root->right;
			add_to_tree(root, dat);
		}
	}
	else
	{
		if (root->left == NULL)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			root->left = temp;
			temp->left = NULL;
			temp->right = NULL;
			temp->data = dat;
		}
		else
		{
			root = root->left;
			add_to_tree(root, dat);
		}
	}
}
void get_inorder(struct node *root)
{
	if (root->left != NULL)
	{
		get_inorder(root->left);
	}
	cout << root->data;
	if (root->right != NULL)
	{
		get_inorder(root->right);
	}
}
void get_preorder(struct node *root)
{
	cout << root->data;
	if (root->left != NULL)
	{
		get_preorder(root->left);
	}
	if (root->right != NULL)
	{
		get_preorder(root->right);
	}
}
void get_postorder(struct node *root)
{
	if (root->left != NULL)
	{
		get_postorder(root->left);
	}
	if (root->right != NULL)
	{
		get_postorder(root->right);
	}
	cout << root->data;
}
int main()
{
	struct node *root, *current;
	cout << "Enter total numbers\n";
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (i==0)
		{
			struct node *temp2 = (struct node *)malloc(sizeof(struct node));
			root = temp2;
			root->left = NULL;
			root->right = NULL;
			root->data = temp;
			continue;
		}
		add_to_tree(root, temp);
	}
	
	get_inorder(root);
	cout << "\n\n";
	get_preorder(root);
	cout << "\n\n";
	get_postorder(root);
	cout << "\n\n";
	return 0;
}