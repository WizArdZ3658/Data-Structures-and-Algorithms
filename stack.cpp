#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct stk
{
	int arr[MAX];
	int top;
};
void push(struct stk &s, int data)
{
	s.top++;
	s.arr[s.top] = data;
}
int pop(struct stk &s)
{
	return s.arr[s.top--]; 
}
int peek(struct stk &s)
{
	return s.arr[s.top];
}
int main()
{
	struct stk s1;
	s1.top = -1;
	cout << "Enter number of elements\n";
	int n, temp;
	cin >> n;
	cout << "Enter elements\n"
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		push(s1, temp);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << pop(s1) << '\n';
	}
	return 0;
}