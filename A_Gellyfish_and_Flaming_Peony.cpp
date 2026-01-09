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

        vector<int> arr(n);
        map<int, int> mp;
        int gcd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            gcd = __gcd(arr[i], gcd);

            mp[arr[i]]++;
        }

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        if (mp[gcd] != 0)
        {
            cout << n - mp[gcd] << endl;
            continue;
        }

        bool pos = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(arr[i], arr[j]) == gcd)
                {
                    pos = true;
                    break;
                }
            }

            if (pos == true)
            {
                break;
            }
        }

        if (pos)
        {
            cout << n << endl;
        }
        else
        {   
            //2 move m to gcd induce kara hi sakte hai na ? 
            cout << n + 1 << endl;
        }

    }
    return 0;
}