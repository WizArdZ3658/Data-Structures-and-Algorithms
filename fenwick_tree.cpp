#include <bits/stdc++.h>
using namespace std;
int BIT[1000], a[1000], n, q;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     cin >> n >> q;
     int i;
     for(i = 1; i <= n; i++)
     {
           cin >> a[i];
           update(i, a[i]);
     }
     cout << "Now enter queries\n";
     while(q--)
     {
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l-1) << '\n';
     }
     return 0;
}