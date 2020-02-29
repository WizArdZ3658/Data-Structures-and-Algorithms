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
void enqueue(struct stk &s, int data)
{
	push(s, data);
}
int dequeue(struct stk &s, struct stk &s2, int n)
{
	for (int i = 0; i < n; ++i)
	{
		push(s2, pop(s));
	}

	int data = pop(s2);

	for (int i = 0; i < n-1; ++i)
	{
		push(s, pop(s2));
	}

	return data;
}
int main()
{
	struct stk s1;
	s1.top = -1;
	struct stk s2;
	s2.top = -1;

	cout << "Enter number of elements\n";
	int n, temp;
	cin >> n;
	cout << "Enter elements\n";
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		enqueue(s1, temp);
	}

	int count = n;
	for (int i = 0; i < n; ++i)
	{
		cout << dequeue(s1, s2, count) << '\n';
		count--;
	}
	return 0;
}