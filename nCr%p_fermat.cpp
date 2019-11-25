/*
go to https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
to understand how this solution works using fermats theorem.
*/
#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll unsigned long long
const ll mod = 1e9 + 7;				//adjust mod value according to your need
const ll limit = 1000000;	
void init_fact(ll arr[])
{
	arr[0] = 1;
	for (ll i = 1; i <= limit; ++i)
		arr[i] = (arr[i-1]*i)%mod;
}
ll power(ll x, ll y) 
{ 
    ll res = 1;
    x = x % mod; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod; 
    } 
    return res; 
}
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
} 
ll nCrmod_fermat(ll n, ll r, ll fac[])
{
	if (r==0) 
      return 1;
    return (fac[n]* modInverse(fac[r]) % mod * modInverse(fac[n-r]) % mod) % mod; 
}
int main()
{
	ll n, r;
	ll factorial[limit+10];
	init_fact(factorial);
	cin >> n >> r;
	cout << nCrmod_fermat(n,r,factorial);
	return 0;
}