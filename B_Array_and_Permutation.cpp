#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n), a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int s = 0, e = 0;

        while (s < n and e < n)
        {
            if (p[s] == a[e])
            {
                s++;

                int ele = a[e];

                while (a[e] == ele)
                {
                    e++;
                }

                if(e==n){
                    s=n;
                    break;
                }
            }
            else
            {
                s++;
            }
        }

        if (s == n and e == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}