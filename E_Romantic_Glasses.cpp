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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<int, int> mp;
        int val = 0;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                val -= arr[i];
            }
            else
            {
                val += arr[i];
            }

            mp[val]++;

            if (mp[val] == 2 or val==0)
            {
                // a subarray exists where sum between elements is zero..i.e alternating sum is zero
                cout << "YES" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}