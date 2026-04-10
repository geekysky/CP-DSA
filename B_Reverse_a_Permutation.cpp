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

        map<int, int> mp;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            mp[arr[i]] = i;
        }

        int comp = n, l = 0, r = LLONG_MAX;
        vector<int> transform;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != comp)
            {
                // this is l -> starting point
                l = i;
                r = mp[comp];

                break;
            }

            comp--;
        }

        if (r != LLONG_MAX)
        {
            // vector is not n,n-1,n-2
            reverse(arr.begin() + l, arr.begin() + r + 1);
        }

        //cout<<l<<" "<<r<<endl;
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}