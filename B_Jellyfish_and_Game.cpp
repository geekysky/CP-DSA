#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n, m, k;
      cin >> n >> m >> k;

      vector<int> a(n), b(m);
      int j = 0, g = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         j += a[i];
      }
      for (int i = 0; i < m; i++)
      {
         cin >> b[i];
         g += b[i];
      }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());

      k %= 2;
      // keep manually track of first two turns
      if (b[m - 1] > a[0])
      {
         // swap takes place
         int temp = a[0];
         j -= a[0];
         a[0] = b[m - 1];
         j += b[m - 1];

         g -= b[m - 1];
         b[m - 1] = temp;
         g += temp;

         sort(a.begin(), a.end());
         sort(b.begin(), b.end());
      }
      int one=j;
      // gellyfish's turn
      if (a[n - 1] > b[0])
      {
         // swap takes place
         int temp = b[0];
         g -= b[0];
         b[0] = a[n - 1];
         g += a[n - 1];

         j -= a[n - 1];
         a[n - 1] = temp;
         j += temp;

         sort(a.begin(), a.end());
         sort(b.begin(), b.end());
      }
      int two=j;

      if(k==0){
         cout<<two<<"\n";
      }
      else{
         cout<<one<<"\n";
      }
   }

   return 0;
}
