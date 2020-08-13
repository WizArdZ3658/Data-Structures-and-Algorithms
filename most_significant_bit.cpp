#include<iostream>
#include<cmath>
using namespace std;
int setBit(int n)
{
	int k = (int)(log2(n));
	return 1<<k;
}
int main()
{
	int n;
	cin >> n;
	cout << "Most significant bits : " << setBit(n) << '\n';
	return 0;
}